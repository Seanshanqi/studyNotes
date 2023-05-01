[46.ȫ����](https://leetcode.cn/problems/permutations/)
����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�  
ʾ�� 1��   

���룺nums = [1,2,3]   
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]  

## ����������
### �ݹ麯������
��������������ģ�Ҳ����˵ [1,2] �� [2,1] ���������ϣ����֮ǰ�������Ӽ��Լ��������ͬ�ĵط���

���Կ���Ԫ��1��[1,2]���Ѿ�ʹ�ù��ˣ�������[2,1]�л�Ҫ��ʹ��һ��1�����Դ�����������Ͳ���ʹ��startIndex�ˡ�  

������������Ҫһ��used���飬����Ѿ�ѡ���Ԫ��  
�������£�
~~~c
vector<vector<int>> result;
vector<int> path;
void backtracking (vector<int>& nums, vector<bool>& used)
~~~

### �ݹ���ֹ����  
���Կ���Ҷ�ӽڵ㣬�����ո����ĵط���

��ôʲôʱ�����ǵ���Ҷ�ӽڵ��أ�

���ռ�Ԫ�ص�����path�Ĵ�С�ﵽ��nums����һ�����ʱ��˵���ҵ���һ��ȫ���У�Ҳ��ʾ������Ҷ�ӽڵ㡣

�������£�

// ��ʱ˵���ҵ���һ��
~~~c
if (path.size() == nums.size()) {
    result.push_back(path);
    return;
}
~~~
### �����������߼�  
�����77.������� (opens new window)��131.�и����� (opens new window)��78.�Ӽ����� (opens new window)���Ĳ�ͬ����forѭ���ﲻ��startIndex�ˡ�  

��Ϊ�������⣬ÿ�ζ�Ҫ��ͷ��ʼ����������Ԫ��1��[1,2]���Ѿ�ʹ�ù��ˣ�������[2,1]�л�Ҫ��ʹ��һ��1��  

��used���飬��ʵ���Ǽ�¼��ʱpath�ﶼ����ЩԪ��ʹ���ˣ�һ��������һ��Ԫ��ֻ��ʹ��һ�Ρ�  

�������£�
~~~c
for (int i = 0; i < nums.size(); i++) {
    if (used[i] == true) continue; // path���Ѿ���¼��Ԫ�أ�ֱ������
    used[i] = true;
    path.push_back(nums[i]);
    backtracking(nums, used);
    path.pop_back();
    used[i] = false;
}
~~~
### ����C++�������£�
~~~c
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // ��ʱ˵���ҵ���һ��
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path���Ѿ���¼��Ԫ�أ�ֱ������
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
~~~
## �ܽ�  
��Ҵ�ʱ���Ը��ܳ���������Ĳ�ͬ��  

ÿ�㶼�Ǵ�0��ʼ����������startIndex  
��Ҫused�����¼path�ﶼ������ЩԪ����  