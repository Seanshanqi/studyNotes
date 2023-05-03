# [47.全排列 II](https://leetcode.cn/problems/permutations-ii/)
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。  

 

### 示例 1：

输入：nums = [1,1,2]  
输出：  
[[1,1,2],  
 [1,2,1],  
 [2,1,1]]  

 这道题目和46.全排列 (opens new window)的区别在与给定一个可包含重复数字的序列，要返回所有不重复的全排列。

这里又涉及到去重了。

在40.组合总和II (opens new window)、90.子集II (opens new window)我们分别详细讲解了组合问题和子集问题如何去重。

那么排列问题其实也是一样的套路。

还要强调的是去重一定要对元素进行排序，这样我们才方便通过相邻的节点来判断是否重复使用了。
一般来说：组合问题和排列问题是在树形结构的叶子节点上收集结果，而子集问题就是取树上所有节点的结果  
~~~c
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
~~~
~~~