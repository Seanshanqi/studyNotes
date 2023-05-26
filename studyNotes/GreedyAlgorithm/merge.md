# [�ϲ�����](https://leetcode.cn/problems/merge-intervals/)
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��

 

ʾ�� 1��  

���룺intervals = [[1,3],[2,6],[8,10],[15,18]]  
�����[[1,6],[8,10],[15,18]]  
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].  
˼·
����ı�����ʵ�����ж��ص��������⡣

���ֺ�452. �����������ļ��������� (opens new window)�� 435. ���ص����� (opens new window)����һ����·��

�⼸���ⶼ���ж������ص�����������ж������ص�����߼����������ж�����������Ҫ��������ϲ���

����һ������·�������������е��������価���ܵ��ص���һ�𣬰���߽磬�����ұ߽����򶼿��ԣ������߼����в�ͬ��

������߽��С��������֮����� intervals[i][0] <= intervals[i - 1][1] ��intervals[i]����߽� <= intervals[i - 1]���ұ߽磬��һ�����ص�����������������Ҳ��������������<=��

֪������ж��ظ�֮��ʣ�µľ��Ǻϲ��ˣ����ȥģ��ϲ������أ�

��ʵ�����úϲ��������߽���ұ߽磬��Ϊһ���µ����䣬���뵽result������Ϳ����ˡ����û�кϲ��Ͱ�ԭ������뵽result���顣

C++�������£�
~~~c
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result; // ���伯��Ϊ��ֱ�ӷ���
        // ����Ĳ���ʹ����lambda���ʽ
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});

        // ��һ������Ϳ��ԷŽ���������������ص�����result��ֱ�Ӻϲ�
        result.push_back(intervals[0]); 

        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) { // �����ص�����
                // �ϲ����䣬ֻ�����ұ߽�ͺã���Ϊresult.back()����߽�һ������Сֵ����Ϊ���ǰ�����߽������
                result.back()[1] = max(result.back()[1], intervals[i][1]); 
            } else {
                result.push_back(intervals[i]); // ���䲻�ص� 
            }
        }
        return result;
    }
};
~~~
ʱ�临�Ӷ�: O(nlogn)
�ռ临�Ӷ�: O(logn)��������Ҫ�Ŀռ俪��