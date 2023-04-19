# [77. 组合](https://leetcode.cn/problems/combinations/description/)
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
## 回溯函数终止条件
什么时候到达所谓的叶子节点了呢？

path这个数组的大小如果达到k，说明我们找到了一个子集大小为k的组合了，
此时用result二维数组，把path保存起来，并终止本层递归。

所以终止条件代码如下：
```c
if (path.size() == k) {
    result.push_back(path);
    return;
}
```
## 单层搜索的过程
```c
for (int i = startIndex; i <= n; i++) { // 控制树的横向遍历
    path.push_back(i); // 处理节点
    backtracking(n, k, i + 1); // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
    path.pop_back(); // 回溯，撤销处理的节点
}
```
## 代码
```c
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};
```
## 剪枝优化

* K - path.size() : 所需要的元素  
* (n - i) 列表中剩余的元素  
*  (n - i) >= k -path.size() 列表中剩余的元素要大于所需要的元素   
*  解得 i <= n - (k - path.size()) + 1 此处加一是因为左闭右闭区间

## 剪枝优化后代码
```c
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking (int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        
        // K - path.size() : 所需要的元素
        // (n - i) 列表中剩余的元素
        // (n - i) >= k -path.size() 列表中剩余的元素要大于所需要的元素
        // 解得 i <= n - (k - path.size()) + 1 此处加一是因为左闭右闭区间
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        backtracking(n, k, 1);
        return res;
    }
};
```