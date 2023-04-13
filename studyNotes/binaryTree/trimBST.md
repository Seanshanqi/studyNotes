# [�޼�����������](https://leetcode.cn/problems/trim-a-binary-search-tree/)
��������������ĸ��ڵ� root ��ͬʱ������С�߽�low �����߽� high��ͨ���޼�������������ʹ�����нڵ��ֵ��[low, high]�С��޼��� ��Ӧ�� �ı䱣�������е�Ԫ�ص���Խṹ (�������û�б��Ƴ���ԭ�еĸ����Ӵ���ϵ��Ӧ������)�� ����֤�������� Ψһ�Ĵ� ��

���Խ��Ӧ�������޼��õĶ������������µĸ��ڵ㡣ע�⣬���ڵ���ܻ���ݸ����ı߽緢���ı䡣  
![](https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg)  
���룺root = [1,0,2], low = 1, high = 2  
�����[1,null,2]  

������
��Ϊ�����������������ԣ�����Ҫʹ��ջģ��ݹ�Ĺ��̡�

�ڼ�֦��ʱ�򣬿��Է�Ϊ������

��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�����
��֦������
��֦������
�������£�
~~~c
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;

        // ����ͷ��㣬��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�
        while (root != nullptr && (root->val < L || root->val > R)) {
            if (root->val < L) root = root->right; // С��L������
            else root = root->left; // ����R������
        }
        TreeNode *cur = root;
        // ��ʱroot�Ѿ���[L, R] ��Χ�ڣ���������Ԫ��С��L�����
        while (cur != nullptr) {
            while (cur->left && cur->left->val < L) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;

        // ��ʱroot�Ѿ���[L, R] ��Χ�ڣ������Һ��Ӵ���R�����
        while (cur != nullptr) {
            while (cur->right && cur->right->val > R) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};
~~~