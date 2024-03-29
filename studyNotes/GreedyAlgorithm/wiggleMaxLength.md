# [376. 摆动序列](https://leetcode.cn/problems/wiggle-subsequence/)
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。  

例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。  

相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。  
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。  

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。  
示例 1：  
 
输入：nums = [1,7,4,9,2,5]  
输出：6  
解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。  
示例 2：  

输入：nums = [1,17,5,10,13,15,10,5,16,8]  
输出：7  
解释：这个序列包含几个长度为 7 摆动序列。   
其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。  
## 思路1（贪心解法）
本题要求通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

这要求最大摆动序列又可以修改数组，这得如何修改呢？

来分析一下，要求删除元素使其达到最大摆动序列，应该删除什么元素呢？
局部最优：删除单调坡度上的节点（不包括单调坡度两端的节点），那么这个坡度就可以有两个局部峰值。

整体最优：整个序列有最多的局部峰值，从而达到最长摆动序列。

局部最优推出全局最优，并举不出反例，那么试试贪心！

（为方便表述，以下说的峰值都是指局部峰值）

实际操作上，其实连删除的操作都不用做，因为题目要求的是最长摆动子序列的长度，所以只需要统计数组的峰值数量就可以了（相当于是删除单一坡度上的节点，然后统计长度）

这就是贪心所贪的地方，让峰值尽可能的保持峰值，然后删除单一坡度上的节点

在计算是否有峰值的时候，大家知道遍历的下标i ，计算prediff（nums[i] - nums[i-1]） 和 curdiff（nums[i+1] - nums[i]），如果prediff < 0 && curdiff > 0 或者 prediff > 0 && curdiff < 0 此时就有波动就需要统计。  

这是我们思考本题的一个大题思路，但本题要考虑三种情况：

情况一：上下坡中有平坡  
情况二：数组首尾两端  
情况三：单调坡中有平坡  
#情况一：上下坡中有平坡  
如果我们采用，删左面三个2的规则，那么 当 prediff = 0 && curdiff < 0 也要记录一个峰值，因为他是把之前相同的元素都删掉留下的峰值。

所以我们记录峰值的条件应该是： (preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)，为什么这里允许 prediff == 0 ，就是为了 上面我说的这种情况。

#情况二：数组首尾两端
所以本题统计峰值的时候，数组最左面和最右面如果统计呢？

题目中说了，如果只有两个不同的元素，那摆动序列也是2。

例如序列[2,5]，如果靠统计差值来计算峰值个数就需要考虑数组最左面和最右面的特殊情况。

因为我们在计算 prediff（nums[i] - nums[i-1]） 和 curdiff（nums[i+1] - nums[i]）的时候，至少需要三个数字才能计算，而数组只有两个数字。

这里我们可以写死，就是 如果只有两个元素，且元素不同，那么结果为2。

不写死的话，如果和我们的判断规则结合在一起呢？

可以假设，数组最前面还有一个数字，那这个数字应该是什么呢？

之前我们在 讨论 情况一：相同数字连续 的时候， prediff = 0 ，curdiff < 0 或者 >0 也记为波谷。

那么为了规则统一，针对序列[2,5]，可以假设为[2,2,5]，这样它就有坡度了即preDiff = 0，  

 针对以上情形，result初始为1（默认最右面有一个峰值），此时curDiff > 0 && preDiff <= 0，那么result++（计算了左面的峰值），最后得到的result就是2（峰值个数为2即摆动序列长度为2）

经过以上分析后，我们可以写出如下代码：

~~~c
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
            }
            preDiff = curDiff;
        }
        return result;
    }
};
~~~
时间复杂度：O(n)
空间复杂度：O(1)