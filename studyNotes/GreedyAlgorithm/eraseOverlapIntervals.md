# [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

 

示例 1:  

输入: intervals = [[1,2],[2,3],[3,4],[1,3]]  
输出: 1  
解释: 移除 [1,3] 后，剩下的区间没有重叠。  

思路
相信很多同学看到这道题目都冥冥之中感觉要排序，但是究竟是按照右边界排序，还是按照左边界排序呢？

其实都可以。主要就是为了让区间尽可能的重叠。

我来按照右边界排序，从左向右记录非交叉区间的个数。最后用区间总数减去非交叉区间的个数就是需要移除的区间个数了。

此时问题就是要求非交叉区间的最大个数。
区间，1，2，3，4，5，6都按照右边界排好序。

当确定区间 1 和 区间2 重叠后，如何确定是否与 区间3 也重贴呢？

就是取 区间1 和 区间2 右边界的最小值，因为这个最小值之前的部分一定是 区间1 和区间2 的重合部分，如果这个最小值也触达到区间3，那么说明 区间 1，2，3都是重合的。

接下来就是找大于区间1结束位置的区间，是从区间4开始。那有同学问了为什么不从区间5开始？别忘了已经是按照右边界排序的了。

区间4结束之后，再找到区间6，所以一共记录非交叉区间的个数是三个。

总共区间个数为6，减去非交叉区间的个数3。移除区间的最小数量就是3。

C++代码如下：
~~~c
class Solution {
public:
    // 按照区间右边界排序
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1; // 记录非交叉区间的个数
        int end = intervals[0][1]; // 记录区间分割点
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
时间复杂度：O(nlog n) ，有一个快排
空间复杂度：O(n)，有一个快排，最差情况(倒序)时，需要n次递归调用。因此确实需要O(n)的栈空间
大家此时会发现如此复杂的一个问题，代码实现却这么简单！