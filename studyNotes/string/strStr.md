## [KMP算法](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)  

* 统一不减一的方法比较好记忆
* 需要注意的部分很多，具体看注释
* 注意getNext函数里是while不是if
```c
//这是next数组统一减一的写法
class Solution {
public:
    void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); i++) { // 注意i从1开始
        while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
            j = next[j]; // 向前回退
        }
        if (s[i] == s[j + 1]) { // 找到相同的前后缀
            j++;
        }
        next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
}
int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

//这是统一不减一的写法！！！！
void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
                j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
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