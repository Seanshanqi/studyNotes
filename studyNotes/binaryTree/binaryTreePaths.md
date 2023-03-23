# [257. ������������·��](https://leetcode.cn/problems/binary-tree-paths/)
����һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����

Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣

## �ݹ�

1. �ݹ麯�������Լ�����ֵ
Ҫ������ڵ㣬��¼ÿһ��·����path���ʹ�Ž������result������ݹ鲻��Ҫ����ֵ���������£�
```c
void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
```
2. ȷ���ݹ���ֹ����
��д�ݹ��ʱ��ϰ������ôд��
```c
if (cur == NULL) {
    ��ֹ�����߼�
}
```

���Ǳ������ֹ��������д����鷳����Ϊ����Ҫ�ҵ�Ҷ�ӽڵ㣬�Ϳ�ʼ�����Ĵ����߼��ˣ���·���Ž�result���

��ôʲôʱ�������ҵ���Ҷ�ӽڵ㣿 �ǵ� cur��Ϊ�գ������Һ��Ӷ�Ϊ�յ�ʱ�򣬾��ҵ�Ҷ�ӽڵ㡣

���Ա������ֹ�����ǣ�

```c
if (cur->left == NULL && cur->right == NULL) {
    ��ֹ�����߼�
}
```
Ϊʲôû���ж�cur�Ƿ�Ϊ���أ���Ϊ������߼����Կ��ƿսڵ㲻��ѭ����

������һ����ֹ������߼���

����ʹ��vector �ṹpath����¼·��������Ҫ��vector �ṹ��pathתΪstring��ʽ���ٰ����string �Ž� result�

��ôΪʲôʹ����vector �ṹ����¼·���أ� ��Ϊ�����洦����ݹ��߼���ʱ��Ҫ�����ݣ�ʹ��vector�����������ݡ�

�����е�ͬѧ���ˣ��ҿ���Щ�˵Ĵ���Ҳû�л��ݰ���

��ʵ���л��ݵģ�ֻ���������ں�������ʱ�Ĳ�����ֵ������һ����ᵽ��

����������ʹ��vector�ṹ��path��������¼·������ô��ֹ�����߼����£�

```c
if (cur->left == NULL && cur->right == NULL) { // ����Ҷ�ӽڵ�
    string sPath;
    for (int i = 0; i < path.size() - 1; i++) { // ��path���¼��·��תΪstring��ʽ
        sPath += to_string(path[i]);
        sPath += "->";
    }
    sPath += to_string(path[path.size() - 1]); // ��¼���һ���ڵ㣨Ҷ�ӽڵ㣩
    result.push_back(sPath); // �ռ�һ��·��
    return;
}
```
3. ȷ������ݹ��߼�
��Ϊ��ǰ���������Ҫ�ȴ����м�ڵ㣬�м�ڵ��������Ҫ��¼·���ϵĽڵ㣬�ȷŽ�path�С�
```c
path.push_back(cur->val);
ccc

Ȼ���ǵݹ�ͻ��ݵĹ��̣�����˵��û���ж�cur�Ƿ�Ϊ�գ���ô������ݹ��ʱ�����Ϊ�վͲ�������һ��ݹ��ˡ�

���Եݹ�ǰҪ�����ж���䣬����Ҫ�ݹ�Ľڵ��Ƿ�Ϊ�գ�����
```c
if (cur->left) {
    traversal(cur->left, path, result);
}
if (cur->right) {
    traversal(cur->right, path, result);
}
```
��ʱ��û�꣬�ݹ��꣬Ҫ�����ݰ�����Ϊpath ����һֱ����ڵ㣬����Ҫɾ�ڵ㣬Ȼ����ܼ����µĽڵ㡣

��ô����Ҫ��ô�����أ�һЩͬѧ����ôд�����£�
```c
if (cur->left) {
    traversal(cur->left, path, result);
}
if (cur->right) {
    traversal(cur->right, path, result);
}
path.pop_back();
```
������ݾ��кܴ�����⣬����֪�������ݺ͵ݹ���һһ��Ӧ�ģ���һ���ݹ飬��Ҫ��һ�����ݣ���ôд�Ļ��൱�ڰѵݹ�ͻ��ݲ��ˣ� һ���ڻ������һ���ڻ������⡣

���Ի���Ҫ�͵ݹ���Զ��һ����������ңԶ�ľ��������ڻ�����������ڻ������⣡

��ô����Ӧ����ôд��
```c
if (cur->left) {
    traversal(cur->left, path, result);
    path.pop_back(); // ����
}
if (cur->right) {
    traversal(cur->right, path, result);
    path.pop_back(); // ����
}
```
��ô��������������£�

```c
class Solution {
private:

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val); // �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path�� 
        // ��ŵ���Ҷ�ӽڵ�
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) { // �� 
            traversal(cur->left, path, result);
            path.pop_back(); // ����
        }
        if (cur->right) { // ��
            traversal(cur->right, path, result);
            path.pop_back(); // ����
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};
```