
# [101. �Գƶ�����](https://leetcode.cn/problems/symmetric-tree/)
* ������������ж϶Գƶ�����Ҫ�Ƚϵ����������ڵ㣬Ҫ�ȽϵĿɲ������ҽڵ㣡
* ���ڶ������Ƿ�Գƣ�Ҫ�Ƚϵ��Ǹ��ڵ�����������������ǲ����໥��ת�ģ������һ���֪������ʵ����Ҫ�Ƚϵ��������������������Ǹ��ڵ�������������������ڵݹ�����Ĺ����У�Ҳ��Ҫͬʱ������������
* ��ô������˳��Ӧ����ʲô�����أ�

    * �������ֻ���ǡ��������������Ϊ����Ҫͨ���ݹ麯���ķ���ֵ���ж������������ڲ�ڵ�����ڵ��Ƿ���ȡ�

    * ������ΪҪ��������������Ҫ�Ƚ��ڲ�����ڵ㣬����׼ȷ����˵��һ�����ı���˳���������У�һ�����ı���˳���������С�

    * ��������������Ǻ�������������Ѿ������ϸ�����һ�����Ͻ��б����ĺ�������ˡ�

## �ݹ鷨
```c
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // �����ų��սڵ�����
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // �ų��˿սڵ㣬���ų���ֵ����ͬ�����
        else if (left->val != right->val) return false;

        // ��ʱ���ǣ����ҽڵ㶼��Ϊ�գ�����ֵ��ͬ�����
        // ��ʱ�����ݹ飬����һ����ж�
        bool outside = compare(left->left, right->right);   // ���������� ����������
        bool inside = compare(left->right, right->left);    // ���������ҡ� ����������
        bool isSame = outside && inside;                    // ���������С� ���������� ���߼�����
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};
```

## ��������ջ�� ������ö��У�ֻ���ջ���ɶ��м���
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();
            if (!leftNode && !rightNode) continue;

            if(!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};
```