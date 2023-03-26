# [513. �������½ǵ�ֵ](https://leetcode.cn/problems/find-bottom-left-tree-value/)
����һ���������� ���ڵ� root�����ҳ��ö������� ��ײ� ����� �ڵ��ֵ��

�����������������һ���ڵ㡣

# ˼·
����ʹ�ò�������ٺ��ʲ����ˣ��ȵݹ�Ҫ�����

ֻ��Ҫ��¼���һ�е�һ���ڵ����ֵ�Ϳ����ˡ�

## ����
```c
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val; // ��¼���һ�е�һ��Ԫ��
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};
```