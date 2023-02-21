using namespace std;
#include <string>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = { 0 };
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // ͨ��recode���ݼ�¼ magazine������ַ����ִ���
            record[magazine[i] - 'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // ����ransomNote����record���Ӧ���ַ�������--����
            record[ransomNote[j] - 'a']--;
            // ���С����˵��ransomNote����ֵ��ַ���magazineû��
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};