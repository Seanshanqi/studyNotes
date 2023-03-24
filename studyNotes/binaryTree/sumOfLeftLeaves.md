# [404. ��Ҷ��֮��](https://leetcode.cn/problems/sum-of-left-leaves/)
�����������ĸ��ڵ� root ������������Ҷ��֮�͡�
## ˼·
����Ҫע�����ж���Ҷ�ӣ����Ƕ��������ڵ㣬���Բ�Ҫ�������Ų��������

��Ϊ��Ŀ����ʵû��˵�����Ҷ�Ӿ�����ʲô�ڵ㣬��Ҷ�ӵ���ȷ���壺�ڵ�A�����Ӳ�Ϊ�գ������ӵ����Һ��Ӷ�Ϊ�գ�˵����Ҷ�ӽڵ㣩����ôA�ڵ������Ϊ��Ҷ�ӽڵ�
## �ݹ鷨

�ݹ�ı���˳��Ϊ��������������У�������ΪҪͨ���ݹ麯���ķ���ֵ���ۼ���ȡ��Ҷ����ֵ֮�͡�

�ݹ���������

* ȷ���ݹ麯���Ĳ����ͷ���ֵ
�ж�һ��������Ҷ�ӽڵ�֮�ͣ���ôһ��Ҫ�������ĸ��ڵ㣬�ݹ麯���ķ���ֵΪ��ֵ֮�ͣ�����Ϊint

ʹ����Ŀ�и����ĺ����Ϳ����ˡ�

* ȷ����ֹ����
����������սڵ㣬��ô��Ҷ��ֵһ����0
```c
if (root == NULL) return 0;
```
ע�⣬ֻ�е�ǰ�����Ľڵ��Ǹ��ڵ㣬�����ж����ӽڵ��ǲ�����Ҷ�ӡ� ���������ǰ�����Ľڵ���Ҷ�ӽڵ㣬������Ҷ��Ҳ�ض���0����ô��ֹ����Ϊ��
```c
if (root == NULL) return 0;
if (root->left == NULL && root->right== NULL) return 0; //��ʵ���Ҳ���Բ�д�������д��Ӱ���������ͻ��õݹ�������һ�㡣
```
* ȷ������ݹ���߼�
��������Ҷ�ӽڵ��ʱ�򣬼�¼��ֵ��Ȼ��ͨ���ݹ���ȡ��������Ҷ��֮�ͣ��� ��������Ҷ��֮�ͣ���ӱ�������������Ҷ��֮�͡�

�������£�
```c
int leftValue = sumOfLeftLeaves(root->left);    // ��
if (root->left && !root->left->left && !root->left->right) {
    leftValue = root->left->val;
}
int rightValue = sumOfLeftLeaves(root->right);  // ��

int sum = leftValue + rightValue;               // ��
return sum;
```

����ݹ�������£�
```c
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right== NULL) return 0;

        int leftValue = sumOfLeftLeaves(root->left);    // ��
        if (root->left && !root->left->left && !root->left->right) { // ����������һ����Ҷ�ӵ����
            leftValue = root->left->val;
        }
        int rightValue = sumOfLeftLeaves(root->right);  // ��

        int sum = leftValue + rightValue;               // ��
        return sum;
    }
};
```
���ϴ��뾫��֮�����£�
```c
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int leftValue = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            leftValue = root->left->val;
        }
        return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```