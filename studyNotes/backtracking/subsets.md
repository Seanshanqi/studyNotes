# [�Ӽ�](https://leetcode.cn/problems/subsets/description/)
����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����

�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��  


ʾ�� 1��  

���룺nums = [1,2,3]  
�����[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]  

����������
�ݹ麯������
ȫ�ֱ�������pathΪ�Ӽ��ռ�Ԫ�أ���ά����result����Ӽ���ϡ���Ҳ���Էŵ��ݹ麯�������

�ݹ麯�����������潲���ˣ���ҪstartIndex��

�������£�
~~~c
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int startIndex) {
~~~
�ݹ���ֹ����

ʣ�༯��Ϊ�յ�ʱ�򣬾���Ҷ�ӽڵ㡣

��ôʲôʱ��ʣ�༯��Ϊ���أ�

����startIndex�Ѿ���������ĳ����ˣ�����ֹ�ˣ���Ϊû��Ԫ�ؿ�ȡ�ˣ���������:
~~~c
if (startIndex >= nums.size()) {
    return;
}
~~~
��ʵ���Բ���Ҫ����ֹ��������ΪstartIndex >= nums.size()������forѭ������Ҳ�����ˡ�

���������߼�
��ȡ�Ӽ����⣬����Ҫ�κμ�֦����Ϊ�Ӽ�����Ҫ������������

��ô����ݹ��߼��������£�
~~~c
for (int i = startIndex; i < nums.size(); i++) {
    path.push_back(nums[i]);    // �Ӽ��ռ�Ԫ��
    backtracking(nums, i + 1);  // ע���i+1��ʼ��Ԫ�ز��ظ�ȡ
    path.pop_back();            // ����
}
~~~

�������
~~~c
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
        if (startIndex >= nums.size()) { // ��ֹ�������Բ���
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
~~~
