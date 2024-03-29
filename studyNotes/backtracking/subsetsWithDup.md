# [90.子集II](https://leetcode.cn/problems/subsets-ii/)
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。   
示例 1：

输入：nums = [1,2,2]  
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]  
示例 2：  
  
输入：nums = [0]  
输出：[[],[0]]  

## 思路
和子集1差不多但是多了重复元素，需要去重，先排序在去重

## 代码
~~~c
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking (const vector<int>& nums, vector<bool>& used, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used, i + 1);
            path.pop_back();
            used[i] = false;
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, 0);
        return res;
    }
};
~~~