# [112. ·���ܺ�](https://leetcode.cn/problems/path-sum/)

����������ĸ��ڵ� root ��һ����ʾĿ��͵����� targetSum ���жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��������·�������нڵ�ֵ��ӵ���Ŀ��� targetSum ��������ڣ����� true �����򣬷��� false ��

Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣

## ˼·

## �ݹ�
����ʹ��������ȱ����ķ�ʽ������ǰ�к��򶼿��ԣ�����ν����Ϊ�нڵ�Ҳû�д����߼���������������  

1. ȷ���ݹ麯���Ĳ����ͷ�������
��������Ҫ�������ĸ��ڵ㣬����Ҫһ����������������������������������һ����֮���Ƿ�������Ŀ��ͣ�������Ϊint�͡�

����������ֵ���ݹ麯��ʲôʱ����Ҫ����ֵ��ʲôʱ����Ҫ����ֵ�������ܽ��������㣺

1. �����Ҫ�������ö������Ҳ��ô���ݹ鷵��ֵ���ݹ麯���Ͳ�Ҫ����ֵ��������������Ǳ����°벿�ֽ��ܵ�113.·���ܺ�ii��
2. �����Ҫ�������ö���������Ҫ����ݹ鷵��ֵ���ݹ麯������Ҫ����ֵ�� ���������������236. ������������������� (opens new window)�н��ܣ�
3. ���Ҫ��������һ������������·������ô�ݹ�һ����Ҫ����ֵ����Ϊ��������������·���˾�Ҫ��ʱ���ء�������������

������·�ߣ�����Ҫ���������������Եݹ麯����Ҫ����ֵ��������bool���ͱ�ʾ��

���Դ������£�

bool traversal(treenode* cur, int count)   // ע�⺯���ķ�������  
2. ȷ����ֹ����  
���ȼ��������ͳ����һ��·���ĺ��أ�   

��Ҫȥ�ۼ�Ȼ���ж��Ƿ����Ŀ��ͣ���ô����Ƚ��鷳�������õݼ����ü�����count��ʼΪĿ��ͣ�Ȼ��ÿ�μ�ȥ����·���ڵ��ϵ���ֵ��

������count == 0��ͬʱ����Ҷ�ӽڵ�Ļ���˵���ҵ���Ŀ��͡�

�����������Ҷ�ӽڵ㣬count��Ϊ0������û�ҵ���

�ݹ���ֹ�����������£�
```c
if (!cur->left && !cur->right && count == 0) return true; // ����Ҷ�ӽڵ㣬���Ҽ���Ϊ0
if (!cur->left && !cur->right) return false; // ����Ҷ�ӽڵ��û���ҵ����ʵıߣ�ֱ�ӷ���
```
ȷ������ݹ���߼�
��Ϊ��ֹ�������ж�Ҷ�ӽڵ㣬���Եݹ�Ĺ����оͲ�Ҫ�ÿսڵ����ݹ��ˡ�

�ݹ麯�����з���ֵ�ģ�����ݹ麯������true��˵���ҵ��˺��ʵ�·����Ӧ�����̷��ء�

�������£�
```c
if (cur->left) { // �� ���սڵ㲻������
    // ����Ҷ�ӽڵ㷵��true����ֱ�ӷ���true
    if (traversal(cur->left, count - cur->left->val)) return true; // ע�������л��ݵ��߼�
}
if (cur->right) { // �� ���սڵ㲻������
    // ����Ҷ�ӽڵ㷵��true����ֱ�ӷ���true
    if (traversal(cur->right, count - cur->right->val)) return true; // ע�������л��ݵ��߼�
}
return false;
```
���ϴ������ǰ����Ż��ݵģ�û�л��ݣ���κ���������һ��·���ء�

����������traversal(cur->left, count - cur->left->val)��� ��Ϊ��count - cur->left->val ֱ����Ϊ��������ȥ������������count����ֵû�иı䡣

Ϊ�˰ѻ��ݵĹ������ֳ��������Ը�Ϊ���´��룺
```c
if (cur->left) { // ��
    count -= cur->left->val; // �ݹ飬����ڵ�;
    if (traversal(cur->left, count)) return true;
    count += cur->left->val; // ���ݣ�����������
}
if (cur->right) { // ��
    count -= cur->right->val;
    if (traversal(cur->right, count)) return true;
    count += cur->right->val;
}
return false;
```
����������£�
```c
class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // ����Ҷ�ӽڵ㣬���Ҽ���Ϊ0
        if (!cur->left && !cur->right) return false; // ����Ҷ�ӽڵ�ֱ�ӷ���

        if (cur->left) { // ��
            count -= cur->left->val; // �ݹ飬����ڵ�;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // ���ݣ�����������
        }
        if (cur->right) { // ��
            count -= cur->right->val; // �ݹ飬����ڵ�;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // ���ݣ�����������
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
};
```