# [40.组合总和Ⅱ](https://leetcode.cn/problems/combination-sum-ii/description/)
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 

 

示例 1:  
  
输入: candidates = [10,1,2,7,6,1,5], target = 8,  
输出:  
[  
[1,1,6],  
[1,2,5],  
[1,7],  
[2,6]  
]  

### 这道题目和39.组合总和 (opens new window)如下区别：  
本题candidates 中的每个数字在每个组合中只能使用一次。    
本题数组candidates的元素是有重复的，而39.组合总和 (opens new window)是无重复元素的数组candidates  
本题的难点在于区别2中：集合（数组candidates）有重复元素，但还不能有重复的组合。   
与39.组合总和 (opens new window)套路相同，此题还需要加一个bool型数组used，用来记录同一树枝上的元素是否使用过。  

这个集合去重的重任就是used来完成的。  
```c
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking (vector<int>& candidates, int target, int startIndex, vector<bool>& used) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1, used);
            used[i] = false;
            path.pop_back();
        }
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, used);
        return res;
    }
};
```

## 这里直接用startIndex来去重也是可以的， 就不用used数组了。
```c
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
```