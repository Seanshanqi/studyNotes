# [93. ��ԭ IP ��ַ](https://leetcode.cn/problems/restore-ip-addresses/description/)
��Ч IP ��ַ �������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0��������֮���� '.' �ָ���  

���磺"0.1.2.201" �� "192.168.1.1" �� ��Ч IP ��ַ������ "0.011.255.245"��"192.168.1.312" �� "192.168@1.1" �� ��Ч IP ��ַ��  
����һ��ֻ�������ֵ��ַ��� s �����Ա�ʾһ�� IP ��ַ���������п��ܵ���Ч IP ��ַ����Щ��ַ����ͨ���� s �в��� '.' ���γɡ��� ���� ���������ɾ�� s �е��κ����֡�����԰� �κ� ˳�򷵻ش𰸡�
ʾ�� 1��  

���룺s = "25525511135"  
�����["255.255.11.135","255.255.111.35"]  
ʾ�� 2��  

���룺s = "0000"  
�����["0.0.0.0"]  
ʾ�� 3��  

���룺s = "101023"  
�����["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]  

## ˼·
��ʵֻҪ��ʶ�������и����⣬�и�����Ϳ���ʹ�û��������������п������ѳ������͸�������131.�ָ���Ĵ� (opens new window)��ʮ�������ˡ�

* �ݹ����
��131.�ָ���Ĵ� (opens new window)�����Ǿ��ᵽ�и���������������⡣

startIndexһ������Ҫ�ģ���Ϊ�����ظ��ָ��¼��һ��ݹ�ָ����ʼλ�á�

�������ǻ���Ҫһ������pointNum����¼��Ӷ����������

���Դ������£�
```c
vector<string> result;// ��¼���
// startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
void backtracking(string& s, int startIndex, int pointNum) {
```
* �ݹ���ֹ����
��ֹ������131.�ָ���Ĵ� (opens new window)����Ͳ�ͬ�ˣ�������ȷҪ��ֻ��ֳ�4�Σ����Բ������и����е������Ϊ��ֹ���������Ƿָ�Ķ�����Ϊ��ֹ������

pointNum��ʾ����������pointNumΪ3˵���ַ����ֳ���4���ˡ�

Ȼ����֤һ�µ��Ķ��Ƿ�Ϸ�������Ϸ��ͼ��뵽�������

�������£�
```c
if (pointNum == 3) { // ��������Ϊ3ʱ���ָ�����
    // �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
    if (isValid(s, startIndex, s.size() - 1)) {
        result.push_back(s);
    }
    return;
}
```

* �����������߼�
��131.�ָ���Ĵ� (opens new window)���Ѿ�������ѭ����������ν�ȡ�Ӵ���

��for (int i = startIndex; i < s.size(); i++)ѭ���� [startIndex, i] ���������ǽ�ȡ���Ӵ�����Ҫ�ж�����Ӵ��Ƿ�Ϸ���

����Ϸ������ַ���������Ϸ���.��ʾ�Ѿ��ָ

������Ϸ��ͽ�������ѭ������ͼ�м����ķ�֧��
Ȼ����ǵݹ�ͻ��ݵĹ��̣�

�ݹ����ʱ����һ��ݹ��startIndexҪ��i+2��ʼ����Ϊ��Ҫ���ַ����м����˷ָ���.����ͬʱ��¼�ָ��������pointNum Ҫ +1��

���ݵ�ʱ�򣬾ͽ��ոռ���ķָ���. ɾ���Ϳ����ˣ�pointNumҲҪ-1��

�������£�
```c
for (int i = startIndex; i < s.size(); i++) {
    if (isValid(s, startIndex, i)) { // �ж� [startIndex,i] ���������Ӵ��Ƿ�Ϸ�
        s.insert(s.begin() + i + 1 , '.');  // ��i�ĺ������һ������
        pointNum++;
        backtracking(s, i + 2, pointNum);   // ���붺��֮����һ���Ӵ�����ʼλ��Ϊi+2
        pointNum--;                         // ����
        s.erase(s.begin() + i + 1);         // ����ɾ������
    } else break; // ���Ϸ���ֱ�ӽ�������ѭ��
}
```
### �ж��Ӵ��Ƿ�Ϸ�
��������дһ���ж϶�λ�Ƿ�����Ч��λ�ˡ�

��Ҫ���ǵ��������㣺

��λ��0Ϊ��ͷ�����ֲ��Ϸ�  
��λ���з��������ַ����Ϸ�  
��λ�������255�˲��Ϸ�  
�������£�
```c
// �ж��ַ���s������ֱ�����[start, end]����ɵ������Ƿ�Ϸ�
bool isValid(const string& s, int start, int end) {
    if (start > end) {
        return false;
    }
    if (s[start] == '0' && start != end) { // 0��ͷ�����ֲ��Ϸ�
            return false;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') { // �����������ַ����Ϸ�
            return false;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) { // �������255�˲��Ϸ�
            return false;
        }
    }
    return true;
}
```
## ����
```c
class Solution {
private:
    vector<string> result;// ��¼���
    // startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // ��������Ϊ3ʱ���ָ�����
            // �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // �ж� [startIndex,i] ���������Ӵ��Ƿ�Ϸ�
                s.insert(s.begin() + i + 1 , '.');  // ��i�ĺ������һ������
                pointNum++;
                backtracking(s, i + 2, pointNum);   // ���붺��֮����һ���Ӵ�����ʼλ��Ϊi+2
                pointNum--;                         // ����
                s.erase(s.begin() + i + 1);         // ����ɾ������
            } else break; // ���Ϸ���ֱ�ӽ�������ѭ��
        }
    }
    // �ж��ַ���s������ֱ�����[start, end]����ɵ������Ƿ�Ϸ�
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0��ͷ�����ֲ��Ϸ�
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // �����������ַ����Ϸ�
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // �������255�˲��Ϸ�
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // ���Ǽ�֦��
        backtracking(s, 0, 0);
        return result;
    }
};
```