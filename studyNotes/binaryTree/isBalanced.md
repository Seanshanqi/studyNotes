# [110. ƽ�������](https://leetcode.cn/problems/balanced-binary-tree/)
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��

һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
## ˼·

�ݹ�
��ʱ���Ӧ�������˼�ȻҪ��Ƚϸ߶ȣ���Ȼ��Ҫ���������

�ݹ�������������

1. ��ȷ�ݹ麯���Ĳ����ͷ���ֵ
��������ǰ����ڵ㡣 ����ֵ���Ե�ǰ����ڵ�Ϊ���ڵ�����ĸ߶ȡ�

��ô��α�����������Ƿ��ֵ����1�أ�

�����ǰ����ڵ�Ϊ���ڵ�Ķ������Ѿ����Ƕ���ƽ�����ˣ������ظ߶ȵĻ���û�������ˡ�

��������Ѿ����Ƕ���ƽ�����ˣ����Է���-1 ������Ѿ�������ƽ�����Ĺ����ˡ�

```c
// -1 ��ʾ�Ѿ�����ƽ��������ˣ����򷵻�ֵ���Ըýڵ�Ϊ���ڵ����ĸ߶�
int getHeight(TreeNode* node)
```

2. ��ȷ��ֹ����
�ݹ�Ĺ�������Ȼ�������սڵ���Ϊ��ֹ������0����ʾ��ǰ�ڵ�Ϊ���ڵ�����߶�Ϊ0

�������£�
```c
if (node == NULL) {
    return 0;
}
```

3. ��ȷ����ݹ���߼�
����ж��Ե�ǰ����ڵ�Ϊ���ڵ�Ķ������Ƿ���ƽ��������أ���Ȼ�����������߶Ⱥ����������߶ȵĲ�ֵ��

�ֱ���������������ĸ߶ȣ�Ȼ�������ֵС�ڵ���1���򷵻ص�ǰ�������ĸ߶ȣ����򷵻�-1����ʾ�Ѿ����Ƕ���ƽ�����ˡ�
```c
int leftHeight = getHeight(node->left); // ��
if (leftHeight == -1) return -1;
int rightHeight = getHeight(node->right); // ��
if (rightHeight == -1) return -1;

int result;
if (abs(leftHeight - rightHeight) > 1) {  // ��
    result = -1;
} else {
    result = 1 + max(leftHeight, rightHeight); // �Ե�ǰ�ڵ�Ϊ���ڵ���������߶�
}

return result;
```
## �������
```c
class Solution {
public:
    int check (TreeNode* root) {
        if (root == NULL) return 0;
        int leftHeight = check(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = check(root->right);
        if (rightHeight == - 1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1; 
        else return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = check(root->left);
        if (left == -1) return false;
        int right = check(root->right);
        if (right == -1) return false;
        return abs(left - right) > 1 ? false : true;
    }
};
```