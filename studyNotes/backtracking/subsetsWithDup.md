# [90.�Ӽ�II](https://leetcode.cn/problems/subsets-ii/)
����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����

�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�   
ʾ�� 1��

���룺nums = [1,2,2]  
�����[[],[1],[1,2],[1,2,2],[2],[2,2]]  
ʾ�� 2��  
  
���룺nums = [0]  
�����[[],[0]]  

## ˼·
���Ӽ�1��൫�Ƕ����ظ�Ԫ�أ���Ҫȥ�أ���������ȥ��

## ����
~~~c
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking (const vector<int>& nums, vector<bool>& used, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used, i + 1);
            path.pop_back();
            used[i] = false;
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, 0);
        return res;
    }
};
~~~