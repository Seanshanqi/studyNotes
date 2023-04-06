# [700.�����������е�����](https://leetcode.cn/problems/search-in-a-binary-search-tree/)
����������������BST���ĸ��ڵ� root ��һ������ֵ val��

����Ҫ�� BST ���ҵ��ڵ�ֵ���� val �Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� null ��
![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)  
���룺root = [4,2,7,1,3], val = 2  
�����[2,1,3]

�ݹ鷨
ȷ���ݹ麯���Ĳ����ͷ���ֵ
�ݹ麯���Ĳ�������ľ��Ǹ��ڵ��Ҫ��������ֵ�����صľ��������������ֵ���ڵĽڵ㡣

�������£�
~~~c
TreeNode* searchBST(TreeNode* root, int val)
~~~
ȷ����ֹ����
���rootΪ�գ������ҵ������ֵ�ˣ��ͷ���root�ڵ㡣
~~~c
if (root == NULL || root->val == val) return root;
~~~
ȷ������ݹ���߼�
���������������ĵ���ݹ��߼��кβ�ͬ��

��Ϊ�����������Ľڵ�������ģ����Կ����з����ȥ������

���root->val > val�����������������root->val < val������������������������û�����������ͷ���NULL��

�������£�
~~~c
TreeNode* result = NULL;
if (root->val > val) result = searchBST(root->left, val);
if (root->val < val) result = searchBST(root->right, val);
return result;
~~~
�ܶ�¼��д�ݹ麯����ʱ�� ϰ��ֱ��д searchBST(root->left, val)��ȴ���� �ݹ麯�����з���ֵ��

�ݹ麯���ķ���ֵ��ʲô? �� �����������������val��Ҫ���ýڵ㷵�ء� �������һ�����������ס����ô����ֵ����û�ˡ�

����Ҫ result = searchBST(root->left, val)��

����������£�
~~~c
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        TreeNode* result = NULL;
        if (root->val > val) result = searchBST(root->left, val);
        if (root->val < val) result = searchBST(root->right, val);
        return result;
    }
};
~~~

