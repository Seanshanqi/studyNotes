# [17. �绰�������ĸ���](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)
## ��Ŀ 
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
```c
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
```

### ȷ�����ݺ�������
������Ҫһ���ַ���s���ռ�Ҷ�ӽڵ�Ľ����Ȼ����һ���ַ�������result������������������������Ȼ����Ϊȫ�֡�

����������������ָ��������Ŀ�и���string digits��Ȼ��Ҫ��һ����������int�͵�index��

ע�����index�ɲ��� 77.��� (opens new window)��216.����ܺ�III (opens new window)�е�startIndex�ˡ�

���index�Ǽ�¼�����ڼ��������ˣ�������������digits�ģ���Ŀ�и��������ַ�������ͬʱindexҲ��ʾ������ȡ�

```c
vector<string> result;
string s;
void backtracking(const string& digits, int index)
```

### ȷ����ֹ����
������������"23"���������֣���ô���ڵ����µݹ�����Ϳ����ˣ�Ҷ�ӽڵ����Ҫ�ռ��Ľ������

��ô��ֹ�����������index ���� ��������ָ�����digits.size���ˣ�����index������������digits�ģ���

Ȼ���ռ��������������ݹ顣
```c
if (index == digits.size()) {
    result.push_back(s);
    return;
}
```

### ȷ����������߼�
����Ҫȡindexָ������֣����ҵ���Ӧ���ַ������ֻ����̵��ַ�������

Ȼ��forѭ������������ַ������������£�

```c
int digit = digits[index] - '0';        // ��indexָ�������תΪint
string letters = letterMap[digit];      // ȡ���ֶ�Ӧ���ַ���
for (int i = 0; i < letters.size(); i++) {
    s.push_back(letters[i]);            // ����
    backtracking(digits, index + 1);    // �ݹ飬ע��index+1��һ�²�Ҫ������һ��������
    s.pop_back();                       // ����
}
```
## ����
```c
class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // ��indexָ�������תΪint
        string letters = letterMap[digit];      // ȡ���ֶ�Ӧ���ַ���
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // ����
            backtracking(digits, index + 1);    // �ݹ飬ע��index+1��һ�²�Ҫ������һ��������
            s.pop_back();                       // ����
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};
```
