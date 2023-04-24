# [131. �ָ���Ĵ�](https://leetcode.cn/problems/palindrome-partitioning/)
����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����

���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����

 

ʾ�� 1��  

���룺s = "aab"  
�����[["a","a","b"],["aa","b"]]  
ʾ�� 2��  

���룺s = "a"  
�����[["a"]]  

* �ݹ麯������
ȫ�ֱ�������path����и����ĵ��Ӵ�����ά����result��Ž������ ���������������Էŵ����������

����ݹ麯����������ҪstartIndex����Ϊ�и���ĵط��������ظ��и���������Ҳ�Ǳ���һ�µġ�

�ڻ����㷨��������ܺͣ����� (opens new window)����������̽�����������ʲôʱ����ҪstartIndex��ʲôʱ����ҪstartIndex��

�������£�
```c
vector<vector<string>> result;
vector<string> path; // ���Ѿ����ĵ��Ӵ�
void backtracking (const string& s, int startIndex) {
```
�ݹ麯����ֹ����  
�и����е����ַ�������棬˵���ҵ���һ���и������ʱ���Ǳ���ݹ����ֹ������
��ô�ڴ�����ʲô���и����أ�  

�ڴ�����������ʱ�򣬵ݹ������Ҫ����startIndex����ʾ��һ�ֵݹ��������ʼλ�ã����startIndex�����и��ߡ�  

������ֹ�����������£�  
```c
void backtracking (const string& s, int startIndex) {
    // �����ʼλ���Ѿ�����s�Ĵ�С��˵���Ѿ��ҵ���һ��ָ����
    if (startIndex >= s.size()) {
        result.push_back(path);
        return;
    }
}
```
�������ڵݹ�ѭ������ν�ȡ�Ӵ��أ�     
��for (int i = startIndex; i < s.size(); i++)ѭ���У����� ��������ʼλ��startIndex����ô [startIndex, i] ����Ҫ��ȡ���Ӵ���  

�����ж�����Ӵ��ǲ��ǻ��ģ�����ǻ��ģ��ͼ�����vector<string> path�У�path������¼�и���Ļ����Ӵ���  

�������£�  
```c
for (int i = startIndex; i < s.size(); i++) {
    if (isPalindrome(s, startIndex, i)) { // �ǻ����Ӵ�
        // ��ȡ[startIndex,i]��s�е��Ӵ�
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
    } else {                // ���������ֱ������
        continue;
    }
    backtracking(s, i + 1); // Ѱ��i+1Ϊ��ʼλ�õ��Ӵ�
    path.pop_back();        // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
}
```
ע���и����λ�ã������ظ��и���ԣ�backtracking(s, i + 1); ������һ�����ʼλ��Ϊi + 1��
## C++�������
```c
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path; // ���Ѿ����ĵ��Ӵ�
    void backtracking (const string& s, int startIndex) {
        // �����ʼλ���Ѿ�����s�Ĵ�С��˵���Ѿ��ҵ���һ��ָ����
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {   // �ǻ����Ӵ�
                // ��ȡ[startIndex,i]��s�е��Ӵ�
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {                                // ���ǻ��ģ�����
                continue;
            }
            backtracking(s, i + 1); // Ѱ��i+1Ϊ��ʼλ�õ��Ӵ�
            path.pop_back(); // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};
```