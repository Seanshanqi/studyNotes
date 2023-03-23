# [257. 二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/)
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。

## 递归

1. 递归函数参数以及返回值
要传入根节点，记录每一条路径的path，和存放结果集的result，这里递归不需要返回值，代码如下：
```c
void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
```
2. 确定递归终止条件
在写递归的时候都习惯了这么写：
```c
if (cur == NULL) {
    终止处理逻辑
}
```

但是本题的终止条件这样写会很麻烦，因为本题要找到叶子节点，就开始结束的处理逻辑了（把路径放进result里）。

那么什么时候算是找到了叶子节点？ 是当 cur不为空，其左右孩子都为空的时候，就找到叶子节点。

所以本题的终止条件是：

```c
if (cur->left == NULL && cur->right == NULL) {
    终止处理逻辑
}
```
为什么没有判断cur是否为空呢，因为下面的逻辑可以控制空节点不入循环。

再来看一下终止处理的逻辑。

这里使用vector 结构path来记录路径，所以要把vector 结构的path转为string格式，再把这个string 放进 result里。

那么为什么使用了vector 结构来记录路径呢？ 因为在下面处理单层递归逻辑的时候，要做回溯，使用vector方便来做回溯。

可能有的同学问了，我看有些人的代码也没有回溯啊。

其实是有回溯的，只不过隐藏在函数调用时的参数赋值里，下文我还会提到。

这里我们先使用vector结构的path容器来记录路径，那么终止处理逻辑如下：

```c
if (cur->left == NULL && cur->right == NULL) { // 遇到叶子节点
    string sPath;
    for (int i = 0; i < path.size() - 1; i++) { // 将path里记录的路径转为string格式
        sPath += to_string(path[i]);
        sPath += "->";
    }
    sPath += to_string(path[path.size() - 1]); // 记录最后一个节点（叶子节点）
    result.push_back(sPath); // 收集一个路径
    return;
}
```
3. 确定单层递归逻辑
因为是前序遍历，需要先处理中间节点，中间节点就是我们要记录路径上的节点，先放进path中。
```c
path.push_back(cur->val);
ccc

然后是递归和回溯的过程，上面说过没有判断cur是否为空，那么在这里递归的时候，如果为空就不进行下一层递归了。

所以递归前要加上判断语句，下面要递归的节点是否为空，如下
```c
if (cur->left) {
    traversal(cur->left, path, result);
}
if (cur->right) {
    traversal(cur->right, path, result);
}
```
此时还没完，递归完，要做回溯啊，因为path 不能一直加入节点，它还要删节点，然后才能加入新的节点。

那么回溯要怎么回溯呢，一些同学会这么写，如下：
```c
if (cur->left) {
    traversal(cur->left, path, result);
}
if (cur->right) {
    traversal(cur->right, path, result);
}
path.pop_back();
```
这个回溯就有很大的问题，我们知道，回溯和递归是一一对应的，有一个递归，就要有一个回溯，这么写的话相当于把递归和回溯拆开了， 一个在花括号里，一个在花括号外。

所以回溯要和递归永远在一起，世界上最遥远的距离是你在花括号里，而我在花括号外！

那么代码应该这么写：
```c
if (cur->left) {
    traversal(cur->left, path, result);
    path.pop_back(); // 回溯
}
if (cur->right) {
    traversal(cur->right, path, result);
    path.pop_back(); // 回溯
}
```
那么本题整体代码如下：

```c
class Solution {
private:

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
        // 这才到了叶子节点
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) { // 左 
            traversal(cur->left, path, result);
            path.pop_back(); // 回溯
        }
        if (cur->right) { // 右
            traversal(cur->right, path, result);
            path.pop_back(); // 回溯
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};
```