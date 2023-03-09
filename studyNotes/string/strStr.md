## [KMP�㷨](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)  

* ͳһ����һ�ķ����ȽϺü���
* ��Ҫע��Ĳ��ֺܶ࣬���忴ע��
* ע��getNext��������while����if
```c
//����next����ͳһ��һ��д��
class Solution {
public:
    void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); i++) { // ע��i��1��ʼ
        while (j >= 0 && s[i] != s[j + 1]) { // ǰ��׺����ͬ��
            j = next[j]; // ��ǰ����
        }
        if (s[i] == s[j + 1]) { // �ҵ���ͬ��ǰ��׺
            j++;
        }
        next[i] = j; // ��j��ǰ׺�ĳ��ȣ�����next[i]
    }
}
int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // ��Ϊnext�������¼����ʼλ��Ϊ-1
        for (int i = 0; i < haystack.size(); i++) { // ע��i�ʹ�0��ʼ
            while(j >= 0 && haystack[i] != needle[j + 1]) { // ��ƥ��
                j = next[j]; // j Ѱ��֮ǰƥ���λ��
            }
            if (haystack[i] == needle[j + 1]) { // ƥ�䣬j��iͬʱ����ƶ�
                j++; // i��������forѭ����
            }
            if (j == (needle.size() - 1) ) { // �ı���s�������ģʽ��t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

//����ͳһ����һ��д����������
void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) { // jҪ��֤����0����Ϊ������ȡj-1��Ϊ�����±�Ĳ���
                j = next[j - 1]; // ע�������Ҫ��ǰһλ�Ķ�Ӧ�Ļ���λ����
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
       if (haystack.size() == 0) return 0;
       int next[needle.size()];
       getNext(next, needle);
       for (int i = 0, j = 0; i < haystack.size(); i++) {
           while (j > 0 && haystack[i] != needle[j]) {
               j = next[j - 1];
           }
           if (haystack[i] == needle[j]) {
               j++;
           }
           
           if (j == needle.size()) {
               return i - needle.size() + 1;
           }
       }
       return -1;
    }

```