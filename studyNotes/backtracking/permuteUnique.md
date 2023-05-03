# [47.ȫ���� II](https://leetcode.cn/problems/permutations-ii/)
����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�  

 

### ʾ�� 1��

���룺nums = [1,1,2]  
�����  
[[1,1,2],  
 [1,2,1],  
 [2,1,1]]  

 �����Ŀ��46.ȫ���� (opens new window)�������������һ���ɰ����ظ����ֵ����У�Ҫ�������в��ظ���ȫ���С�

�������漰��ȥ���ˡ�

��40.����ܺ�II (opens new window)��90.�Ӽ�II (opens new window)���Ƿֱ���ϸ���������������Ӽ��������ȥ�ء�

��ô����������ʵҲ��һ������·��

��Ҫǿ������ȥ��һ��Ҫ��Ԫ�ؽ��������������ǲŷ���ͨ�����ڵĽڵ����ж��Ƿ��ظ�ʹ���ˡ�
һ����˵�������������������������νṹ��Ҷ�ӽڵ����ռ���������Ӽ��������ȡ�������нڵ�Ľ��  
~~~c
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // ��ʱ˵���ҵ���һ��
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true��˵��ͬһ��֦nums[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
            // ���ͬһ����nums[i - 1]ʹ�ù���ֱ������
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ����
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
~~~
~~~