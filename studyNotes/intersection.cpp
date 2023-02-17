#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // ��Ž����֮������set��Ϊ�˸������ȥ��
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // ����nums2��Ԫ�� ��nums_set���ֳ��ֹ�
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};