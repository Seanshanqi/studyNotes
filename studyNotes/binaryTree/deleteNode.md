# [ɾ�������������еĽڵ�](https://leetcode.cn/problems/delete-node-in-a-bst/)
����һ�������������ĸ��ڵ� root ��һ��ֵ key��ɾ�������������е� key ��Ӧ�Ľڵ㣬����֤���������������ʲ��䡣���ض������������п��ܱ����£��ĸ��ڵ�����á�

һ����˵��ɾ���ڵ�ɷ�Ϊ�������裺

�����ҵ���Ҫɾ���Ľڵ㣻  
����ҵ��ˣ�ɾ������  
![](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)  
���룺root = [5,3,6,2,4,null,7], key = 3
�����[5,4,6,2,null,null,7]
���ͣ�������Ҫɾ���Ľڵ�ֵ�� 3���������������ҵ� 3 ����ڵ㣬Ȼ��ɾ������
һ����ȷ�Ĵ��� [5,4,6,2,null,null,7], ����ͼ��ʾ��  
��һ����ȷ���� [5,2,6,null,4,null,7]��  

![](https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg)  

# �ݹ�
�ݹ���������

ȷ���ݹ麯�������Լ�����ֵ
˵���ݹ麯���ķ���ֵ���ڶ��������������еĲ������ (opens new window)��ͨ���ݹ鷵��ֵ�������½ڵ㣬 ����Ҳ����ͨ���ݹ鷵��ֵɾ���ڵ㡣

�������£�
~~~c
TreeNode* deleteNode(TreeNode* root, int key)
~~~
ȷ����ֹ����
�����շ��أ���ʵ��Ҳ˵��û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
~~~c
if (root == nullptr) return root;
~~~
ȷ������ݹ���߼�
����ͰѶ�����������ɾ���ڵ�������������������

���������������

��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
�ҵ�ɾ���Ľڵ�
�ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
�����������ɾ���ڵ������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ�������Һ���Ϊ���ڵ�
�����������ɾ���ڵ���Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ��������ͷ��㣨���ӣ��ŵ�ɾ���ڵ����������������ڵ�������ϣ�����ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣

�������£�
~~~c
if (root->val == key) {
    // �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
    // �����������������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ �������Һ���Ϊ���ڵ�
    if (root->left == nullptr) return root->right;
    // ��������������Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
    else if (root->right == nullptr) return root->left;
    // ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ���������ŵ�ɾ���ڵ����������������ڵ�����ӵ�λ��
    // ������ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
    else {
        TreeNode* cur = root->right; // ��������������Ľڵ�
        while(cur->left != nullptr) {
            cur = cur->left;
        }
        cur->left = root->left; // ��Ҫɾ���Ľڵ㣨root������������cur�����ӵ�λ��
        TreeNode* tmp = root;   // ��root�ڵ㱣��һ�£�������ɾ��
        root = root->right;     // ���ؾ�root���Һ�����Ϊ��root
        delete tmp;             // �ͷŽڵ��ڴ棨���ﲻдҲ���ԣ���C++����ֶ��ͷ�һ�°ɣ�
        return root;
    }
}
~~~
�����൱�ڰ��µĽڵ㷵�ظ���һ�㣬��һ���Ҫ�� root->left ���� root->right��ס���������£�
~~~c
if (root->val > key) root->left = deleteNode(root->left, key);
if (root->val < key) root->right = deleteNode(root->right, key);
return root;
~~~

����������£���ע���У����1��2��3��4��5����������ϸ��Ӧ��
~~~c
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; // ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
        if (root->val == key) {
            // �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
            if (root->left == nullptr && root->right == nullptr) {
                ///! �ڴ��ͷ�
                delete root;
                return nullptr;
            }
            // �����������������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ �������Һ���Ϊ���ڵ�
            else if (root->left == nullptr) {
                auto retNode = root->right;
                ///! �ڴ��ͷ�
                delete root;
                return retNode;
            }
            // ��������������Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
            else if (root->right == nullptr) {
                auto retNode = root->left;
                ///! �ڴ��ͷ�
                delete root;
                return retNode;
            }
            // ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ���������ŵ�ɾ���ڵ����������������ڵ�����ӵ�λ��
            // ������ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
            else {
                TreeNode* cur = root->right; // ��������������Ľڵ�
                while(cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left; // ��Ҫɾ���Ľڵ㣨root������������cur�����ӵ�λ��
                TreeNode* tmp = root;   // ��root�ڵ㱣��һ�£�������ɾ��
                root = root->right;     // ���ؾ�root���Һ�����Ϊ��root
                delete tmp;             // �ͷŽڵ��ڴ棨���ﲻдҲ���ԣ���C++����ֶ��ͷ�һ�°ɣ�
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
~~~