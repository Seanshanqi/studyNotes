#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô�����ܴճ���Ԫ��
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //��Ԫ��Ԫ��aȥ��
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                    && nums[j] == nums[j - 1]
                    && nums[j - 1] == nums[j - 2]) { // ��Ԫ��Ԫ��bȥ��
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({ nums[i], nums[j], c });
                    set.erase(c);// ��Ԫ��Ԫ��cȥ��
                }
                else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};