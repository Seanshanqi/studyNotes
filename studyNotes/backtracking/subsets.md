# [子集](https://leetcode.cn/problems/subsets/description/)
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。  


示例 1：  

输入：nums = [1,2,3]  
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]  

回溯三部曲
递归函数参数
全局变量数组path为子集收集元素，二维数组result存放子集组合。（也可以放到递归函数参数里）

递归函数参数在上面讲到了，需要startIndex。

代码如下：
~~~c
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int startIndex) {
~~~
递归终止条件

剩余集合为空的时候，就是叶子节点。

那么什么时候剩余集合为空呢？

就是startIndex已经大于数组的长度了，就终止了，因为没有元素可取了，代码如下:
~~~c
if (startIndex >= nums.size()) {
    return;
}
~~~
其实可以不需要加终止条件，因为startIndex >= nums.size()，本层for循环本来也结束了。

单层搜索逻辑
求取子集问题，不需要任何剪枝！因为子集就是要遍历整棵树。

那么单层递归逻辑代码如下：
~~~c
for (int i = startIndex; i < nums.size(); i++) {
    path.push_back(nums[i]);    // 子集收集元素
    backtracking(nums, i + 1);  // 注意从i+1开始，元素不重复取
    path.pop_back();            // 回溯
}
~~~

整体代码
~~~c
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex >= nums.size()) { // 终止条件可以不加
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
~~~
