# [40.����ܺ͢�](https://leetcode.cn/problems/combination-sum-ii/description/)
����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�

candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ�� ��

ע�⣺�⼯���ܰ����ظ�����ϡ� 

 

ʾ�� 1:  
  
����: candidates = [10,1,2,7,6,1,5], target = 8,  
���:  
[  
[1,1,6],  
[1,2,5],  
[1,7],  
[2,6]  
]  

### �����Ŀ��39.����ܺ� (opens new window)��������  
����candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�    
��������candidates��Ԫ�������ظ��ģ���39.����ܺ� (opens new window)�����ظ�Ԫ�ص�����candidates  
������ѵ���������2�У����ϣ�����candidates�����ظ�Ԫ�أ������������ظ�����ϡ�   
��39.����ܺ� (opens new window)��·��ͬ�����⻹��Ҫ��һ��bool������used��������¼ͬһ��֦�ϵ�Ԫ���Ƿ�ʹ�ù���  

�������ȥ�ص����ξ���used����ɵġ�  
```c
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking (vector<int>& candidates, int target, int startIndex, vector<bool>& used) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1, used);
            used[i] = false;
            path.pop_back();
        }
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, used);
        return res;
    }
};
```

## ����ֱ����startIndex��ȥ��Ҳ�ǿ��Եģ� �Ͳ���used�����ˡ�
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
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1); // ��39.����ܺ͵�����1��������i+1��ÿ��������ÿ�������ֻ��ʹ��һ��
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        // ���ȰѸ�candidates����������ͬ��Ԫ�ض�����һ��
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
```