# [�����������еĲ������](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)
����������������BST���ĸ��ڵ� root ��Ҫ�������е�ֵ value ����ֵ��������������� ���ز��������������ĸ��ڵ㡣 �������� ��֤ ����ֵ��ԭʼ�����������е�����ڵ�ֵ����ͬ��

ע�⣬���ܴ��ڶ�����Ч�Ĳ��뷽ʽ��ֻҪ���ڲ�����Ա���Ϊ�������������ɡ� ����Է��� ������Ч�Ľ�� ��  
![](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)  
���룺root = [4,2,7,1,3], val = 5  
�����[4,2,7,1,3,5]  
���ͣ���һ��������ĿҪ�����ͨ�������ǣ�  
![](https://assets.leetcode.com/uploads/2020/10/05/bst.jpg)  
�ݹ�
�ݹ���������

ȷ���ݹ麯�������Լ�����ֵ
�������Ǹ��ڵ�ָ�룬�Լ�Ҫ����Ԫ�أ�����ݹ麯��Ҫ��Ҫ�з���ֵ�أ�

�����У�Ҳ����û�У����ݹ麯�����û�з���ֵ�Ļ���ʵ���ǱȽ��鷳�ģ�����Ҳ����������ʵ�ִ��롣

�з���ֵ�Ļ����������÷���ֵ����¼���Ľڵ����丸�ڵ�ĸ�ֵ��������������һ�����ͣ�

�ݹ麯���ķ�������Ϊ�ڵ�����TreeNode * ��

�������£�

TreeNode* insertIntoBST(TreeNode* root, int val)
ȷ����ֹ����
��ֹ���������ҵ������Ľڵ�Ϊnull��ʱ�򣬾���Ҫ����ڵ��λ���ˣ����Ѳ���Ľڵ㷵�ء�

�������£�

if (root == NULL) {
    TreeNode* node = new TreeNode(val);
    return node;
}
�������ӵĽڵ㷵�ظ���һ�㣬������˸��ӽڵ�ĸ�ֵ�����ˣ���ϸ�����¿���

ȷ������ݹ���߼�
��ʱҪ��ȷ����Ҫ����������ô��

����������������������������������ֱ�Ƕ������������裬������

���������з����ˣ����Ը��ݲ���Ԫ�ص���ֵ�������ݹ鷽��

�������£�

if (root->val > val) root->left = insertIntoBST(root->left, val);
if (root->val < val) root->right = insertIntoBST(root->right, val);
return root;
��������Ӧ���ܸ��ܵ������ͨ���ݹ麯������ֵ������¼���ڵ�ĸ��ӹ�ϵ��ֵ�����ˣ���һ�㽫����ڵ㷵�أ�������root->left����root->right�����ס��

����������£�
~~~c
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};
~~~
���Կ������벢�����ӡ�

�ո�˵�˵ݹ麯�����÷���ֵҲ���ԣ��ҵ�����Ľڵ�λ�ã�ֱ�����丸�ڵ�ָ�����ڵ㣬�����ݹ飬Ҳ�ǿ��Եġ�

��ô�ݹ麯���������£�
~~~c
TreeNode* parent; // ��¼�����ڵ�ĸ��ڵ�
void traversal(TreeNode* cur, int val)
~~~
û�з���ֵ����Ҫ��¼��һ���ڵ㣨parent���������սڵ��ˣ�����parent���ӻ����Һ���ָ���²���Ľڵ㡣Ȼ������ݹ顣

�������£�
~~~c
class Solution {
private:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) {
        if (cur == NULL) {
            TreeNode* node = new TreeNode(val);
            if (val > parent->val) parent->right = node;
            else parent->left = node;
            return;
        }
        parent = cur;
        if (cur->val > val) traversal(cur->left, val);
        if (cur->val < val) traversal(cur->right, val);
        return;
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent = new TreeNode(0);
        if (root == NULL) {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
};
~~~
���Կ��������鷳һЩ�ġ�

֮���Ծ�������ӣ�����˵��ͨ���ݹ麯���ķ���ֵ��ɸ��ӽڵ�ĸ�ֵ�ǿ��Դ��������ġ�

