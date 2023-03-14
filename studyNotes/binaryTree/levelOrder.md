# [102. �������Ĳ������](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

* ��Ҫ����һ���������ݽṹ��������ʵ�֣������Ƚ��ȳ�������һ��һ��������߼�������ջ�Ƚ�����ʺ�ģ��������ȱ���Ҳ���ǵݹ���߼���

* �����ֲ��������ʽ����ͼ���еĹ�����ȱ�����ֻ��������Ӧ���ڶ������ϡ�
```c
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()����Ϊque.size�ǲ��ϱ仯��
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
```