# �ַ��� 
## [541. ��ת�ַ��� II](https://leetcode.cn/problems/reverse-string-ii/description/)

 �����ַ����Ĺ����У�ֻҪ�� i += (2 * k)��i ÿ���ƶ� 2 * k �Ϳ����ˣ�Ȼ���ж��Ƿ���Ҫ�з�ת������
 
```c
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
            // 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
```