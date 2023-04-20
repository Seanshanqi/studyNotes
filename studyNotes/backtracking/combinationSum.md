# [39. ����ܺ�](https://leetcode.cn/problems/combination-sum/description/)
����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�

candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ� 

���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����

 

ʾ�� 1��

���룺candidates = [2,3,6,7], target = 7  
�����[[2,2,3],[7]]  
���ͣ�  
2 �� 3 �����γ�һ���ѡ��2 + 2 + 3 = 7 ��ע�� 2 ����ʹ�ö�Ρ�  
7 Ҳ��һ����ѡ�� 7 = 7 ��  
������������ϡ�  

## ˼·
* ���ܼ�������֮�������һ���sum�����Ǳ���� sum + candidates[i]���Ѿ�����target���Ϳ��Խ�������forѭ���ı�����

```c
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // ��� sum + candidates[i] > target ����ֹ����
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // ��Ҫ����
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
```