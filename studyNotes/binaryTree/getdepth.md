# [104.��������������](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)
�������ʹ��ǰ�������ң���Ҳ����ʹ�ú�������������У���ʹ��ǰ����ľ�����ȣ�ʹ�ú�������Ǹ߶ȡ�

## ˼·
�������ڵ����ȣ�ָ�Ӹ��ڵ㵽�ýڵ�����·���ߵ��������߽ڵ�����ȡ������ȴ�0��ʼ���Ǵ�1��ʼ��  
�������ڵ�ĸ߶ȣ�ָ�Ӹýڵ㵽Ҷ�ӽڵ�����·���ߵ��������߽ڵ�����ȡ���ڸ߶ȴ�0��ʼ���Ǵ�1��ʼ��  
�����ڵ�ĸ߶Ⱦ��Ƕ������������ȣ����Ա���������ͨ��������ĸ��ڵ�߶�����Ķ����������ȡ�

��һ����ʵ�Ǻܶ�ͬѧû��������ģ��ܶ����ͬ��û�н������

�����ú�������������У����������ĸ߶ȡ�

1. ȷ���ݹ麯���Ĳ����ͷ���ֵ���������Ǵ������ĸ��ڵ㣬���ؾͷ������������ȣ����Է���ֵΪint���͡�
```c 
int getdepth(treenode* node)
```
2. ȷ����ֹ���������Ϊ�սڵ�Ļ����ͷ���0����ʾ�߶�Ϊ0��
```c
if (node == NULL) return 0;
```
3. ȷ������ݹ���߼���������������������ȣ���������������ȣ����ȡ�������������ֵ ��+1 ����1����Ϊ���ϵ�ǰ�м�ڵ㣩����Ŀǰ�ڵ�Ϊ���ڵ��������ȡ�
```c
int leftdepth = getdepth(node->left);       // ��
int rightdepth = getdepth(node->right);     // ��
int depth = 1 + max(leftdepth, rightdepth); // ��
return depth;
```
* �������
```c
class solution {
public:
    int getdepth(treenode* node) {
        if (node == NULL) return 0;
        int leftdepth = getdepth(node->left);       // ��
        int rightdepth = getdepth(node->right);     // ��
        int depth = 1 + max(leftdepth, rightdepth); // ��
        return depth;
    }
    int maxdepth(treenode* root) {
        return getdepth(root);
    }
};
```
* �����
```c
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```

# [111.����������С���](https://www.programmercarl.com/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.html#�ݹ鷨)
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ֱ���Ϻ�����������Ȳ�࣬��ʵ���ǲ�ٵġ�

������Ȼ��ǰ������ͺ�����������ԣ�ǰ���������ȣ���������Ǹ߶ȡ�

* �������ڵ����ȣ�ָ�Ӹ��ڵ㵽�ýڵ�����·���ߵ��������߽ڵ�����ȡ������ȴ�0��ʼ���Ǵ�1��ʼ��
* �������ڵ�ĸ߶ȣ�ָ�Ӹýڵ㵽Ҷ�ӽڵ�����·���ߵ��������߽ڵ�����ȡ���ڸ߶ȴ�0��ʼ���Ǵ�1��ʼ��
��ôʹ�ú����������ʵ����Ǹ��ڵ㵽Ҷ�ӽڵ����С���룬������߶ȵĹ��̣����������С���� Ҳͬ������С��ȡ�

���½����б���˳������Ȼ���ú����������ΪҪ�Ƚϵݹ鷵��֮��Ľ����������Ҳ����ǰ�������д������

���⻹��һ���������ڴ���ڵ�Ĺ����У������Ⱥ�������⣬��С��ȾͲ���ô�����.  
������������ˣ���Ŀ��˵���ǣ���С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ���������ע����Ҷ�ӽڵ㡣
```c
class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);           // ��
        int rightDepth = getDepth(node->right);         // ��
                                                        // ��
        // ��һ��������Ϊ�գ��Ҳ�Ϊ�գ���ʱ��������͵�
        if (node->left == NULL && node->right != NULL) { 
            return 1 + rightDepth;
        }   
        // ��һ��������Ϊ�գ���Ϊ�գ���ʱ��������͵�
        if (node->left != NULL && node->right == NULL) { 
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
```