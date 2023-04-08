# [530. ��������������С���Բ�](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)
����һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ��

��ֵ��һ������������ֵ������ֵ֮��ľ���ֵ��   
![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)  
���룺root = [4,2,6,1,3]   
�����1  

## ˼·  
��Ŀ��Ҫ���ڶ������������������ڵ�Ĳ�ľ���ֵ����Сֵ��

ע���Ƕ�����������������������������ġ�

�����ڶ�������������ʲô��ֵ������ֵ֮��ģ��Ͱ��������һ����������������ֵ�����ֵ�������ͼ򵥶��ˡ�

## �ݹ�
��ô�������������������������ʵ����һ���������顣

��һ����������������������С��ֵ�����ǲ��Ǿ���һ���ͷ����ˡ�

��ֱ�۵��뷨�����ǰѶ���������ת�����������飬Ȼ�����һ�����飬��ͳ�Ƴ�����С��ֵ�ˡ�

�������£�
~~~c
class Solution {
private:
vector<int> vec;
void traversal(TreeNode* root) {
    if (root == NULL) return;
    traversal(root->left);
    vec.push_back(root->val); // ������������ת��Ϊ��������
    traversal(root->right);
}
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) { // ͳ�������������С��ֵ
            result = min(result, vec[i] - vec[i-1]);
        }
        return result;
    }
};
~~~
���ϴ����ǰѶ���������ת��Ϊ���������ˣ���ʵ�ڶ�����������������Ĺ����У����ǾͿ���ֱ�Ӽ����ˡ�

��Ҫ��һ��pre�ڵ��¼һ��cur�ڵ��ǰһ���ڵ㡣  
�������£�
~~~c
class Solution {
private:
int result = INT_MAX;
TreeNode* pre = NULL;
void traversal(TreeNode* cur) {
    if (cur == NULL) return;
    traversal(cur->left);   // ��
    if (pre != NULL){       // ��
        result = min(result, cur->val - pre->val);
    }
    pre = cur; // ��¼ǰһ��
    traversal(cur->right);  // ��
}
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};
~~~