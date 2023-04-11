[236. �������������������](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����  
![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)  

���룺root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1  
�����3  
���ͣ��ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3 ��  

˼·
���������Ŀ���������Ҫ�����Ե����ϲ��Ҿͺ��ˣ������Ϳ����ҵ����������ˡ�

��ô��������ο����Ե����ϲ����أ�

���ݰ������������ݵĹ��̾��Ǵӵ͵��ϡ�

��������������У�������Ȼ�Ļ��ݹ��̣����Ը������������ķ���ֵ���������нڵ���߼���

�������Ϳ�����ж�һ���ڵ��ǽڵ�q�ͽڵ�p�Ĺ��������ء�

�����������뵽��һ�����������ҵ�һ���ڵ㣬�������������ֽ��p�����������ֽڵ�q������ ���������ֽ��q�����������ֽڵ�p����ô�ýڵ���ǽڵ�p��q������������ȡ�

��Ŀǿ�����������ڵ���ֵ�ǲ��ظ��ģ�����һ������ q �� p��

���Ǻܶ������׺���һ����������ǽڵ㱾��p(q)����ӵ��һ������ڵ�q(p)    
��ʵ���һ �� ����� ����ʵ�ֹ��̶���һ���ģ�Ҳ����˵��ʵ�����һ���߼���˳��������������  

��Ϊ���� q ���� p �ͷ��أ�����Ҳ������ q ���� p �������� �������ȵ������  
�ݹ���������

ȷ���ݹ麯������ֵ�Լ�����
��Ҫ�ݹ麯������ֵ�������������Ƿ��ҵ��ڵ�q����p����ô����ֵΪbool���;Ϳ����ˡ�

�����ǻ�Ҫ������������ڵ㣬������������Ŀ�з���ֵ��TreeNode * ����ô�������p����q���Ͱ�q����p���أ�����ֵ��Ϊ�գ���˵���ҵ���q����p��

�������£�
~~~c
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
~~~
ȷ����ֹ����
�����յĻ�����Ϊ�����ǿ��ˣ����Է��ؿա�

��ô������˵һ˵����� root == q������ root == p��˵���ҵ� q p �����䷵�أ��������ֵ���������нڵ�Ĵ��������л��õ�����ô�нڵ�Ĵ����߼������潲�⡣

�������£�
~~~c
if (root == q || root == p || root == NULL) return root;
~~~
ȷ������ݹ��߼�
ֵ��ע����� ���⺯���з���ֵ������Ϊ���ݵĹ�����Ҫ�ݹ麯���ķ���ֵ���жϣ�������������ȻҪ�����������нڵ㡣

�����ڶ��������ݹ麯������ʲôʱ����Ҫ����ֵ��ʲôʱ��Ҫ����ֵ�� (opens new window)��˵�� �ݹ麯���з���ֵ����Ҫ����ĳһ���ߣ����з���ֵҲҪ����δ�������ֵ��

����ݹ麯���з���ֵ���������Ҫ����һ���ߣ����������������أ�

����һ���ߵ�д����
~~~c
if (�ݹ麯��(root->left)) return ;

if (�ݹ麯��(root->right)) return ;
����������д����

left = �ݹ麯��(root->left);  // ��
right = �ݹ麯��(root->right); // ��
left��right���߼�����;         // �� 

~~~

�ڵݹ麯���з���ֵ������£����Ҫ����һ���ߣ��ݹ麯������ֵ��Ϊ�յ�ʱ�����̷��أ����������������ֱ����һ������left��right��ס����ֵ�����left��right�������߼���������Ҫ��Ҳ���Ǻ�������д����м�ڵ���߼���Ҳ�ǻ��ݣ���

��ôΪʲôҪ�����������أ�ֱ�����������ҵ�����������ȣ�ֱ��һ·���ؾͿ����ˡ�   
����ʵ�ϻ�Ҫ�������ڵ�����������ʹ��ʱ�Ѿ��ҵ���Ŀ��ڵ��ˣ���Ҳ����ͼ�еĽڵ�4��15��20��

��Ϊ�����´���ĺ�������У����������left��right���߼������� �������̷��أ�����Ҫ��left��right�߼�������֮����ܷ��ء�
~~~c
left = �ݹ麯��(root->left);  // ��
right = �ݹ麯��(root->right); // ��
left��right���߼�����;         // �� 
~~~
���Դ�ʱ���Ҫ֪������Ҫ������������֪����һ�㣬�Ա������һ����ȵ������ˡ�

��ô����left��right��ס���������������ķ���ֵ���������£�
~~~c
TreeNode* left = lowestCommonAncestor(root->left, p, q);
TreeNode* right = lowestCommonAncestor(root->right, p, q);
~~~
���left �� right����Ϊ�գ�˵����ʱroot������������ڵ㡣����ȽϺ�����

���leftΪ�գ�right��Ϊ�գ��ͷ���right��˵��Ŀ��ڵ���ͨ��right���صģ���֮��Ȼ��  
����������£�
~~~c
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == q || root == p || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;

        if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else  { //  (left == NULL && right == NULL)
            return NULL;
        }

    }
}; 
~~~