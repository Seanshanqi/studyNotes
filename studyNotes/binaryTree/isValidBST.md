# [98. ��֤����������](https://leetcode.cn/problems/validate-binary-search-tree/)
����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������

��Ч �����������������£�

�ڵ��������ֻ���� С�� ��ǰ�ڵ������
�ڵ��������ֻ���� ���� ��ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������  
![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)  
���룺root = [2,1,3]  
�����true  

## ˼·
Ҫ֪����������£�����Ķ����������ڵ����ֵ���������С�

����������ԣ���֤���������������൱�ڱ�����ж�һ�������ǲ��ǵ������ˡ�  

��Ѱ��һ�������������Ľڵ㣬���û���ҵ�����ڵ�ͱ�����������������ҵ������ϵĽڵ��ˣ����̷��ء�

�������£�
~~~c
long long maxVal = LONG_MIN; // ��Ϊ��̨������������int��Сֵ
bool isValidBST(TreeNode* root)
~~~
ȷ����ֹ����
����ǿսڵ� �ǲ��Ƕ����������أ�

�ǵģ�����������Ҳ����Ϊ��

�������£�
~~~c
if (root == NULL) return true;
~~~
ȷ������ݹ���߼�
���������һֱ����maxVal��һ������maxVal >= root->val���ͷ���false��ע��Ԫ����ͬʱ��ҲҪ����false��

�������£�
~~~c
bool left = isValidBST(root->left);         // ��

// �����������֤������Ԫ���ǲ��Ǵ�С����
if (maxVal < root->val) maxVal = root->val; // ��
else return false;

bool right = isValidBST(root->right);       // ��
return left && right;
����������£�

class Solution {
public:
    long long maxVal = LONG_MIN; // ��Ϊ��̨������������int��Сֵ
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        // �����������֤������Ԫ���ǲ��Ǵ�С����
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};
~~~
~~~