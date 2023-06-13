# [435. ���ص�����](https://leetcode.cn/problems/non-overlapping-intervals/)
����һ������ļ��� intervals ������ intervals[i] = [starti, endi] ������ ��Ҫ�Ƴ��������С������ʹʣ�����以���ص� ��

 

ʾ�� 1:  

����: intervals = [[1,2],[2,3],[3,4],[1,3]]  
���: 1  
����: �Ƴ� [1,3] ��ʣ�µ�����û���ص���  

˼·
���źܶ�ͬѧ���������Ŀ��ڤڤ֮�ио�Ҫ���򣬵��Ǿ����ǰ����ұ߽����򣬻��ǰ�����߽������أ�

��ʵ�����ԡ���Ҫ����Ϊ�������価���ܵ��ص���

���������ұ߽����򣬴������Ҽ�¼�ǽ�������ĸ��������������������ȥ�ǽ�������ĸ���������Ҫ�Ƴ�����������ˡ�

��ʱ�������Ҫ��ǽ����������������
���䣬1��2��3��4��5��6�������ұ߽��ź���

��ȷ������ 1 �� ����2 �ص������ȷ���Ƿ��� ����3 Ҳ�����أ�

����ȡ ����1 �� ����2 �ұ߽����Сֵ����Ϊ�����Сֵ֮ǰ�Ĳ���һ���� ����1 ������2 ���غϲ��֣���������СֵҲ���ﵽ����3����ô˵�� ���� 1��2��3�����غϵġ�

�����������Ҵ�������1����λ�õ����䣬�Ǵ�����4��ʼ������ͬѧ����Ϊʲô��������5��ʼ���������Ѿ��ǰ����ұ߽�������ˡ�

����4����֮�����ҵ�����6������һ����¼�ǽ�������ĸ�����������

�ܹ��������Ϊ6����ȥ�ǽ�������ĸ���3���Ƴ��������С��������3��

C++�������£�
~~~c
class Solution {
public:
    // ���������ұ߽�����
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1; // ��¼�ǽ�������ĸ���
        int end = intervals[0][1]; // ��¼����ָ��
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
~~~
ʱ�临�Ӷȣ�O(nlog n) ����һ������
�ռ临�Ӷȣ�O(n)����һ�����ţ�������(����)ʱ����Ҫn�εݹ���á����ȷʵ��ҪO(n)��ջ�ռ�
��Ҵ�ʱ�ᷢ����˸��ӵ�һ�����⣬����ʵ��ȴ��ô�򵥣�