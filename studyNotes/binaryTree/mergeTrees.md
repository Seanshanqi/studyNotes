# [617.合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)

给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。

## 递归
二叉树使用递归，就要想使用前中后哪种遍历方式？

本题使用哪种遍历都是可以的

617.合并二叉树

那么我们来按照递归三部曲来解决：

确定递归函数的参数和返回值：
首先要合入两个二叉树，那么参数至少是要传入两个二叉树的根节点，返回值就是合并之后二叉树的根节点。

代码如下：
~~~c
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
~~~
确定终止条件：
因为是传入了两个树，那么就有两个树遍历的节点t1 和 t2，如果t1 == NULL 了，两个树合并就应该是 t2 了（如果t2也为NULL也无所谓，合并之后就是NULL）。

反过来如果t2 == NULL，那么两个数合并就是t1（如果t1也为NULL也无所谓，合并之后就是NULL）。

代码如下：
~~~c++
if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
~~~
确定单层递归的逻辑：
单层递归的逻辑就比较好写了，这里我们重复利用一下t1这个树，t1就是合并之后树的根节点（就是修改了原来树的结构）。

那么单层递归中，就要把两棵树的元素加到一起。

t1->val += t2->val;
接下来t1 的左子树是：合并 t1左子树 t2左子树之后的左子树。

t1 的右子树：是 合并 t1右子树 t2右子树之后的右子树。

最终t1就是合并之后的根节点。

代码如下：
~~~c++
t1->left = mergeTrees(t1->left, t2->left);
t1->right = mergeTrees(t1->right, t2->right);
return t1;
~~~
此时前序遍历，完整代码就写出来了，如下：
~~~c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
        if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
        // 修改了t1的数值和结构
        t1->val += t2->val;                             // 中
        t1->left = mergeTrees(t1->left, t2->left);      // 左
        t1->right = mergeTrees(t1->right, t2->right);   // 右
        return t1;
    }
};
~~~