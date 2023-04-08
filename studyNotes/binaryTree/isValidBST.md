# [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。  
![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)  
输入：root = [2,1,3]  
输出：true  

## 思路
要知道中序遍历下，输出的二叉搜索树节点的数值是有序序列。

有了这个特性，验证二叉搜索树，就相当于变成了判断一个序列是不是递增的了。  

在寻找一个不符合条件的节点，如果没有找到这个节点就遍历了整个树，如果找到不符合的节点了，立刻返回。

代码如下：
~~~c
long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
bool isValidBST(TreeNode* root)
~~~
确定终止条件
如果是空节点 是不是二叉搜索树呢？

是的，二叉搜索树也可以为空

代码如下：
~~~c
if (root == NULL) return true;
~~~
确定单层递归的逻辑
中序遍历，一直更新maxVal，一旦发现maxVal >= root->val，就返回false，注意元素相同时候也要返回false。

代码如下：
~~~c
bool left = isValidBST(root->left);         // 左

// 中序遍历，验证遍历的元素是不是从小到大
if (maxVal < root->val) maxVal = root->val; // 中
else return false;

bool right = isValidBST(root->right);       // 右
return left && right;
整体代码如下：

class Solution {
public:
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};
~~~
~~~