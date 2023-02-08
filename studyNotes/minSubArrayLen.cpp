#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; // ���յĽ��
        int sum = 0; // �����е���ֵ֮��
        int subLength = 0; // �����еĳ���
        for (int i = 0; i < nums.size(); i++) { // �������������Ϊi
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // ������������ֹλ��Ϊj
                sum += nums[j];
                if (sum >= s) { // һ�����������кͳ�����s������result
                    subLength = j - i + 1; // ȡ�����еĳ���
                    result = result < subLength ? result : subLength;
                    break; // ��Ϊ�������ҷ���������̵������У�����һ������������break
                }
            }
        }
        // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
        return result == INT32_MAX ? 0 : result;
    }
};