
## [��ָ Offer 58 - II. ����ת�ַ���](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/)
1.��תǰn���ַ�  
2.�ٷ�תn��ĩβ���ַ�  
3.�ٽ������ַ�����ת
```c++
class Solution {
public:
    void reverse (string& s, int begin, int end) {
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n - 1);
        reverse(s, n, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        return s;
    }
};
```