# �������ĵ�������
## [144. ��������ǰ�����](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

* ����ջʵ��
* ע������пսڵ㲻��ջ
```c
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // ��
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // �ң��սڵ㲻��ջ��
            if (node->left) st.push(node->left);             // �󣨿սڵ㲻��ջ��
        }
        return result;
    }
};
```
## [94. ���������������](https://leetcode.cn/problems/binary-tree-inorder-traversal/)
1. ������Ԫ�طŽ�result������
2. ���ʣ������ڵ�  

����һ��Ϊʲô�ո�д��ǰ������Ĵ��룬���ܺ��������ͨ���أ���Ϊǰ�������˳���������ң��ȷ��ʵ�Ԫ�����м�ڵ㣬Ҫ�����Ԫ��Ҳ���м�ڵ㣬���Ըող���д����Լ��Ĵ��룬��ΪҪ���ʵ�Ԫ�غ�Ҫ�����Ԫ��˳����һ�µģ������м�ڵ㡣

��ô�ٿ��������������������������ң��ȷ��ʵ��Ƕ����������Ľڵ㣬Ȼ��һ��һ�����·��ʣ�ֱ���������������ײ����ٿ�ʼ����ڵ㣨Ҳ�����ڰѽڵ����ֵ�Ž�result�����У����������˴���˳��ͷ���˳���ǲ�һ�µġ�

��ô��ʹ�õ�����д�������������Ҫ����ָ��ı������������ʽڵ㣬ջ����������ڵ��ϵ�Ԫ�ء�
```c
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
                st.push(cur); // �����ʵĽڵ�Ž�ջ
                cur = cur->left;                // ��
            } else {
                cur = st.top(); // ��ջ�ﵯ�������ݣ�����Ҫ��������ݣ��Ž�result����������ݣ�
                st.pop();
                result.push_back(cur->val);     // ��
                cur = cur->right;               // ��
            }
        }
        return result;
    }
};
```



