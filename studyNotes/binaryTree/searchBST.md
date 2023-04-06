# [700.二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/)
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)  
输入：root = [4,2,7,1,3], val = 2  
输出：[2,1,3]

递归法
确定递归函数的参数和返回值
递归函数的参数传入的就是根节点和要搜索的数值，返回的就是以这个搜索数值所在的节点。

代码如下：
~~~c
TreeNode* searchBST(TreeNode* root, int val)
~~~
确定终止条件
如果root为空，或者找到这个数值了，就返回root节点。
~~~c
if (root == NULL || root->val == val) return root;
~~~
确定单层递归的逻辑
看看二叉搜索树的单层递归逻辑有何不同。

因为二叉搜索树的节点是有序的，所以可以有方向的去搜索。

如果root->val > val，搜索左子树，如果root->val < val，就搜索右子树，最后如果都没有搜索到，就返回NULL。

代码如下：
~~~c
TreeNode* result = NULL;
if (root->val > val) result = searchBST(root->left, val);
if (root->val < val) result = searchBST(root->right, val);
return result;
~~~
很多录友写递归函数的时候 习惯直接写 searchBST(root->left, val)，却忘了 递归函数还有返回值。

递归函数的返回值是什么? 是 左子树如果搜索到了val，要将该节点返回。 如果不用一个变量将其接住，那么返回值不就没了。

所以要 result = searchBST(root->left, val)。

整体代码如下：
~~~c
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        TreeNode* result = NULL;
        if (root->val > val) result = searchBST(root->left, val);
        if (root->val < val) result = searchBST(root->right, val);
        return result;
    }
};
~~~

