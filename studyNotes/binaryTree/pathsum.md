# [113. ·���ܺ�ii](https://leetcode.cn/problems/path-sum-ii/)
����������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����

Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣

## ˼·
·���ܺ�iiҪ�������������ҵ�����·�������Եݹ麯����Ҫ����ֵ��
## ����
~~~c
class solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // �ݹ麯������Ҫ����ֵ����Ϊ����Ҫ����������
    void traversal(treenode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) { // ������Ҷ�ӽڵ����ҵ��˺�Ϊsum��·��
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return ; // ����Ҷ�ӽڵ��û���ҵ����ʵıߣ�ֱ�ӷ���

        if (cur->left) { // �� ���սڵ㲻������
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);    // �ݹ�
            count += cur->left->val;        // ����
            path.pop_back();                // ����
        }
        if (cur->right) { // �� ���սڵ㲻������
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);   // �ݹ�
            count += cur->right->val;       // ����
            path.pop_back();                // ����
        }
        return ;
    }

public:
    vector<vector<int>> pathsum(treenode* root, int sum) {
        result.clear();
        path.clear();
        if (root == null) return result;
        path.push_back(root->val); // �Ѹ��ڵ�Ž�·��
        traversal(root, sum - root->val);
        return result;
    }
};
~~~

