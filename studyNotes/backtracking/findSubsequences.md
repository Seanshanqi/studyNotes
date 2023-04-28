# [491.����������](https://leetcode.cn/problems/non-decreasing-subsequences/)
����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�  

�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ�����������  

 

ʾ�� 1��  

���룺nums = [4,6,7,7]  
�����[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]  
������������бȽ�����ȡ������Ӽ������ұ���ҲҪ��������ͬ�ĵ��������С�

�������Ӽ�������ȥ�أ��ǲ��ǲ��������������˸ոս�����90.�Ӽ�II (opens new window)��

������Ϊ̫���ˣ���Ҫע�������ڣ�Ҫ���͵������ˣ�

��90.�Ӽ�II (opens new window)��������ͨ�������ټ�һ������������ﵽȥ�ص�Ŀ�ġ�

�����������������У��ǲ��ܶ�ԭ�����������ģ�����������鶼�������������ˡ�

���Բ���ʹ��֮ǰ��ȥ���߼���
  
���������ʾ��������һ���������� [4, 6, 7, 7]����������󵼰��������˼·ȥ���ˡ�  

## ����������
�ݹ麯������  
�����������У�������һ��Ԫ�ز����ظ�ʹ�ã�������ҪstartIndex��������һ��ݹ����ʼλ�á�  

�������£�  
~~~c
vector<vector<int>> result;  
vector<int> path;
void backtracking(vector<int>& nums, int startIndex)
~~~
��ֹ����
������ʵ�������Ӽ����⣬Ҳ��Ҫ�������νṹ��ÿһ���ڵ㣬���Ժͻ����㷨�����Ӽ����⣡ (opens new window)һ�������Բ�����ֹ������startIndexÿ�ζ����1�����������޵ݹ顣

�������ռ����������ͬ����ĿҪ����������д�С����Ϊ2�����Դ������£�
~~~c
if (path.size() > 1) {
    result.push_back(path);
    // ע�����ﲻҪ��return����ΪҪȡ���ϵ����нڵ�
}
~~~
���������߼�

���������������£�
~~~c
unordered_set<int> uset; // ʹ��set���Ա���Ԫ�ؽ���ȥ��
for (int i = startIndex; i < nums.size(); i++) {
    if ((!path.empty() && nums[i] < path.back())
            || uset.find(nums[i]) != uset.end()) {
            continue;
    }
    uset.insert(nums[i]); // ��¼���Ԫ���ڱ����ù��ˣ�������治��������
    path.push_back(nums[i]);
    backtracking(nums, i + 1);
    path.pop_back();
}
~~~
�����Ѿ�ϰ��д���ݵ�ͬѧ�������ݹ麯�������uset.insert(nums[i]);������ȴû�ж�Ӧ��pop֮��Ĳ�����Ӧ�úܲ�ϰ�߰ɣ�����

��Ҳ����Ҫע��ĵ㣬unordered_set<int> uset; �Ǽ�¼����Ԫ���Ƿ��ظ�ʹ�ã��µ�һ��uset�������¶��壨��գ�������Ҫ֪��usetֻ���𱾲㣡

�������C++�������£�
~~~c
// �汾һ
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
            // ע�����ﲻҪ��return��Ҫȡ���ϵĽڵ�
        }
        unordered_set<int> uset; // ʹ��set�Ա���Ԫ�ؽ���ȥ��
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                    || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]); // ��¼���Ԫ���ڱ����ù��ˣ�������治��������
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
~~~

## �Ż�
���ϴ�����������unordered_set<int>����¼����Ԫ���Ƿ��ظ�ʹ�á�

��ʵ������������ϣ��Ч�ʾ͸��˺ܶࡣ

ע����Ŀ��˵�ˣ���ֵ��Χ[-100,100]��������ȫ����������������ϣ��

�������е�ʱ���unordered_set Ƶ����insert��unordered_set��Ҫ����ϣӳ�䣨Ҳ���ǰ�keyͨ��hash functionӳ��ΪΨһ�Ĺ�ϣֵ����Է�ʱ�䣬����ÿ�����¶���set��insert��ʱ����ײ�ķ��ű�ҲҪ����Ӧ�����䣬Ҳ�Ƿ��µġ�

��ô�Ż���Ĵ������£�
~~~c
// �汾��
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        int used[201] = {0}; // ����ʹ������������ȥ�ز�������Ŀ˵��ֵ��Χ[-100, 100]
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                    || used[nums[i] + 100] == 1) {
                    continue;
            }
            used[nums[i] + 100] = 1; // ��¼���Ԫ���ڱ����ù��ˣ�������治��������
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
~~~
��ݴ�����leetcode���ύ��Ҫ�Ȱ汾һ��ʱҪ�õĶࡣ

���������ڹ�ϣ���ܽ�ƪ����ÿ���ܽ�ؾ��䣩 (opens new window)��˵�����������飬set��map����������ϣ����������ɵĻmap��set���ܸɣ��������ֵ��ΧС�Ļ��������龡�������顣