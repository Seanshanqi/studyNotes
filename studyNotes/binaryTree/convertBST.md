# [538. �Ѷ���������ת��Ϊ�ۼ���](https://leetcode.cn/problems/convert-bst-to-greater-tree/)
�������� ���� ���ĸ��ڵ㣬�����Ľڵ�ֵ������ͬ�����㽫��ת��Ϊ�ۼ�����Greater Sum Tree����ʹÿ���ڵ� node ����ֵ����ԭ���д��ڻ���� node.val ��ֵ֮�͡�

����һ�£�������������������Լ��������

�ڵ���������������� С�� �ڵ���Ľڵ㡣  
�ڵ���������������� ���� �ڵ���Ľڵ㡣  
��������Ҳ�����Ƕ�����������  
## ʾ��
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png)  
���룺[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]  
�����[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]  
## �ݹ�

�ݹ麯�������Լ�����ֵ
�������ȷ�ˣ�����Ҫ�ݹ麯���ķ���ֵ��ʲô�����ˣ�Ҫ������������

ͬʱ��Ҫ����һ��ȫ�ֱ���pre����������cur�ڵ��ǰһ���ڵ����ֵ������Ϊint�;Ϳ����ˡ�

�������£�
~~~c
int pre = 0; // ��¼ǰһ���ڵ����ֵ
void traversal(TreeNode* cur)
~~~
ȷ����ֹ����
���վ���ֹ��
~~~ 
if (cur == NULL) return;
~~~
ȷ������ݹ���߼�
ע��Ҫ�������������������� �нڵ�Ĵ����߼�������cur����ֵ����ǰһ���ڵ����ֵ��

�������£�
~~~c
traversal(cur->right);  // ��
cur->val += pre;        // ��
pre = cur->val;
traversal(cur->left);   // ��
~~~
�ݹ鷨����������£�
~~~c
class Solution {
private:
    int pre = 0; // ��¼ǰһ���ڵ����ֵ
    void traversal(TreeNode* cur) { // ���������
        if (cur == NULL) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};
~~~

## ������
~~~c
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return NULL;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->right;
            }
            else {
                cur = st.top();
                st.pop();
                if (pre) cur->val += pre->val;
                pre = cur;
                cur = cur->left;
            }
        }
        return root;
    }
};
~~~