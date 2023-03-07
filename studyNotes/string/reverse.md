
## [剑指 Offer 58 - II. 左旋转字符串](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/)
1.翻转前n个字符  
2.再翻转n到末尾的字符  
3.再将整个字符串翻转
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