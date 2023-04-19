# [77. ���](https://leetcode.cn/problems/combinations/description/)
������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�

����԰� �κ�˳�� ���ش𰸡�

 

ʾ�� 1��

���룺n = 4, k = 2
�����
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
## ���ݺ�����ֹ����
ʲôʱ�򵽴���ν��Ҷ�ӽڵ����أ�

path�������Ĵ�С����ﵽk��˵�������ҵ���һ���Ӽ���СΪk������ˣ�
��ʱ��result��ά���飬��path��������������ֹ����ݹ顣

������ֹ�����������£�
```c
if (path.size() == k) {
    result.push_back(path);
    return;
}
```
## ���������Ĺ���
```c
for (int i = startIndex; i <= n; i++) { // �������ĺ������
    path.push_back(i); // ����ڵ�
    backtracking(n, k, i + 1); // �ݹ飺�����������������ע����һ������Ҫ��i+1��ʼ
    path.pop_back(); // ���ݣ���������Ľڵ�
}
```
## ����
```c
class Solution {
private:
    vector<vector<int>> result; // ��ŷ�����������ļ���
    vector<int> path; // ������ŷ����������
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // ����ڵ�
            backtracking(n, k, i + 1); // �ݹ�
            path.pop_back(); // ���ݣ���������Ľڵ�
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // ���Բ�д
        path.clear();   // ���Բ�д
        backtracking(n, k, 1);
        return result;
    }
};
```
## ��֦�Ż�

* K - path.size() : ����Ҫ��Ԫ��  
* (n - i) �б���ʣ���Ԫ��  
*  (n - i) >= k -path.size() �б���ʣ���Ԫ��Ҫ��������Ҫ��Ԫ��   
*  ��� i <= n - (k - path.size()) + 1 �˴���һ����Ϊ����ұ�����

## ��֦�Ż������
```c
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking (int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        
        // K - path.size() : ����Ҫ��Ԫ��
        // (n - i) �б���ʣ���Ԫ��
        // (n - i) >= k -path.size() �б���ʣ���Ԫ��Ҫ��������Ҫ��Ԫ��
        // ��� i <= n - (k - path.size()) + 1 �˴���һ����Ϊ����ұ�����
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        backtracking(n, k, 1);
        return res;
    }
};
```