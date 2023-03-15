# [226. ��ת������](https://leetcode.cn/problems/invert-binary-tree/)
* ע��ֻҪ��ÿһ���ڵ�����Һ��ӷ�תһ�£��Ϳ��Դﵽ���巭ת��Ч��

* �����Ŀʹ��ǰ������ͺ�����������ԣ�Ψ��������������㣬��Ϊ����������ĳЩ�ڵ�����Һ��ӷ�ת�����Σ�
## �ݹ鷨
```c
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);  // ��
        invertTree(root->left);         // ��
        invertTree(root->right);        // ��
        return root;
    }
};
```
## ������
```c 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();              // ��
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);   // ��
            if(node->left) st.push(node->left);     // ��
        }
        return root;
    }
};
```