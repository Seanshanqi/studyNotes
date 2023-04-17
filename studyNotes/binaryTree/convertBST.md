# [538. 把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/)
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。  
节点的右子树仅包含键 大于 节点键的节点。  
左右子树也必须是二叉搜索树。  
## 示例
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png)  
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]  
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]  
## 递归

递归函数参数以及返回值
这里很明确了，不需要递归函数的返回值做什么操作了，要遍历整棵树。

同时需要定义一个全局变量pre，用来保存cur节点的前一个节点的数值，定义为int型就可以了。

代码如下：
~~~c
int pre = 0; // 记录前一个节点的数值
void traversal(TreeNode* cur)
~~~
确定终止条件
遇空就终止。
~~~ 
if (cur == NULL) return;
~~~
确定单层递归的逻辑
注意要右中左来遍历二叉树， 中节点的处理逻辑就是让cur的数值加上前一个节点的数值。

代码如下：
~~~c
traversal(cur->right);  // 右
cur->val += pre;        // 中
pre = cur->val;
traversal(cur->left);   // 左
~~~
递归法整体代码如下：
~~~c
class Solution {
private:
    int pre = 0; // 记录前一个节点的数值
    void traversal(TreeNode* cur) { // 右中左遍历
        if (cur == NULL) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};
~~~

## 迭代法
~~~c
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return NULL;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->right;
            }
            else {
                cur = st.top();
                st.pop();
                if (pre) cur->val += pre->val;
                pre = cur;
                cur = cur->left;
            }
        }
        return root;
    }
};
~~~