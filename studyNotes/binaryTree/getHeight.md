# [����ƽ����](https://leetcode.cn/problems/balanced-binary-tree/description/)
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��

ʾ�� 1:

���������� [3,9,20,null,null,15,7]

* ������Ϊ������߼���ʵ����ĸ��ڵ�ĸ߶ȣ������ڵ�ĸ߶Ⱦ���������������ȣ����Բſ���ʹ�ú��������

��ʱ�����˼�ȻҪ��Ƚϸ߶ȣ���Ȼ��Ҫ���������

�ݹ�������������

1. ��ȷ�ݹ麯���Ĳ����ͷ���ֵ
��������ǰ����ڵ㡣
����ֵ���Ե�ǰ����ڵ�Ϊ���ڵ�����ĸ߶ȡ�

��ô��α�����������Ƿ��ֵ����1�أ�

�����ǰ����ڵ�Ϊ���ڵ�Ķ������Ѿ����Ƕ���ƽ�����ˣ������ظ߶ȵĻ���û�������ˡ�

��������Ѿ����Ƕ���ƽ�����ˣ����Է���-1 ������Ѿ�������ƽ�����Ĺ����ˡ�

�������£�
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

�������£�
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
## �����������
```c
class Solution {
public:
    // �����Ըýڵ�Ϊ���ڵ�Ķ������ĸ߶ȣ��������ƽ����������򷵻�-1
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
```