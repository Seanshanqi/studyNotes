# [222.��ȫ�������Ľڵ����](https://leetcode.cn/problems/count-complete-tree-nodes/submissions/406628090/)
����һ����ȫ����������������Ľڵ������

ʾ�� 1��

���룺root = [1,2,3,4,5,6]
�����6
ʾ�� 2��

���룺root = []
�����0
ʾ�� 3��

���룺root = [1]
�����1
��ʾ��

���нڵ����Ŀ��Χ��[0, 5 * 10^4]
0 <= Node.val <= 5 * 10^4
��Ŀ���ݱ�֤��������� ��ȫ������
## ˼·
����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~ 2^(h-1)  ���ڵ㡣

���Ҫ�Լ�����ȫ�������Ķ��壬�ܶ�ͬѧ����ȫ��������ʵ���������Ķ��ˡ�
��ȫ������ֻ��������������һ��������������������������һ��Ҷ�ӽڵ�û������

�������һ������ֱ���� 2^����� - 1 �����㣬ע��������ڵ����Ϊ1��

������������ֱ�ݹ����ӣ����Һ��ӣ��ݹ鵽ĳһ���һ���������ӻ����Һ���Ϊ����������Ȼ����Ȼ���԰������1�����㡣
```c
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0; // �����ʼΪ0����Ŀ�ĵģ�Ϊ��������ָ������
        while (left) {  // �����������
            left = left->left;
            leftDepth++;
        }
        while (right) { // �����������
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // ע��(2<<1) �൱��2^2������leftDepth��ʼΪ0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```