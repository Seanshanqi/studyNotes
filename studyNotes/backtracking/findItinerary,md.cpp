[332.重新安排行程]()

给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程["JFK", "LGA"] 与["JFK", "LGB"] 相比就更小，排序更靠前。
示例：![](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)  

假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
输入：tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出：["JFK", "MUC", "LHR", "SFO", "SJC"]

该记录映射关系
有多种解法，字母序靠前排在前面，如何该记录映射关系呢 ？

一个机场映射多个机场，机场之间要靠字母序排列，一个机场映射多个机场，可以使用std::unordered_map，如果让多个机场之间再有顺序的话，就是用std::map 或者std::multimap 或者 std::multiset。

如果对map 和 set 的实现机制不太了解，也不清楚为什么 map、multimap就是有序的同学，可以看这篇文章关于哈希表，你该了解这些！(opens new window)。

这样存放映射关系可以定义为 unordered_map<string, multiset<string>> targets 或者 unordered_map<string, map<string, int>> targets。

含义如下：

unordered_map<string, multiset> targets：unordered_map<出发机场, 到达机场的集合> targets

unordered_map<string, map<string, int>> targets：unordered_map<出发机场, map<到达机场, 航班次数>> targets

这两个结构，我选择了后者，因为如果使用unordered_map<string, multiset<string>> targets 遍历multiset的时候，不能删除元素，一旦删除元素，迭代器就失效了。

再说一下为什么一定要增删元素呢，正如开篇我给出的图中所示，出发机场和到达机场是会重复的，搜索的过程没及时删除目的机场就会死循环。

所以搜索的过程中就是要不断的删multiset里的元素，那么推荐使用unordered_map<string, map<string, int>> targets。

在遍历 unordered_map<出发机场, map<到达机场, 航班次数>> targets的过程中，可以使用"航班次数"这个字段的数字做相应的增减，来标记到达机场是否使用过了。

如果“航班次数”大于零，说明目的地还可以飞，如果“航班次数”等于零说明目的地不能飞了，而不用对集合做删除元素或者增加元素的操作。

相当于说我不删，我就做一个标记！

#回溯法
这道题目我使用回溯法，那么下面按照我总结的回溯模板来：
~~~c
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
~~~

开始回溯三部曲讲解：

递归函数参数
在讲解映射关系的时候，已经讲过了，使用unordered_map<string, map<string, int>> targets; 来记录航班的映射关系，我定义为全局变量。

当然把参数放进函数里传进去也是可以的，我是尽量控制函数里参数的长度。

参数里还需要ticketNum，表示有多少个航班（终止条件会用上）。

代码如下：
~~~c
// unordered_map<出发机场, map<到达机场, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result) {
    ~~~
        注意函数返回值我用的是bool！

        我们之前讲解回溯算法的时候，一般函数返回值都是void，这次为什么是bool呢？

        当然本题的targets和result都需要初始化，代码如下：
        ~~~c
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
    result.push_back("JFK"); // 起始机场
    ~~~
        递归终止条件
        拿题目中的示例为例，输入 : [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]] ，这是有4个航班，那么只要找出一种行程，行程里的机场个数是5就可以了。

        所以终止条件是：我们回溯遍历的过程中，遇到的机场个数，如果达到了（航班数量 + 1），那么我们就找到了一个行程，把所有航班串在一起了。

        代码如下：
        ~~~c
        if (result.size() == ticketNum + 1) {
            return true;
        }
    ~~~
        已经看习惯回溯法代码的同学，到叶子节点了习惯性的想要收集结果，但发现并不需要，本题的result相当于 回溯算法：求组合总和！(opens new window)中的path，也就是本题的result就是记录路径的（就一条），在如下单层搜索的逻辑中result就添加元素了。

        单层搜索的逻辑
        回溯的过程中，如何遍历一个机场所对应的所有机场呢？

        这里刚刚说过，在选择映射函数的时候，不能选择unordered_map<string, multiset<string>> targets， 因为一旦有元素增删multiset的迭代器就会失效，当然可能有牛逼的容器删除元素迭代器不会失效，这里就不在讨论了。

        可以说本题既要找到一个对数据进行排序的容器，而且还要容易增删元素，迭代器还不能失效。

        所以我选择了unordered_map<string, map<string, int>> targets 来做机场之间的映射。

        遍历过程如下：
        ~~~c
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) { // 记录到达机场是否飞过了
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
    ~~~
        可以看出 通过unordered_map<string, map<string, int>> targets里的int字段来判断 这个集合里的机场是否使用过，这样避免了直接去删元素。

        分析完毕，此时完整C++代码如下：
        ~~~c
        class Solution {
        private:
            // unordered_map<出发机场, map<到达机场, 航班次数>> targets
            unordered_map<string, map<string, int>> targets;
            bool backtracking(int ticketNum, vector<string>& result) {
                if (result.size() == ticketNum + 1) {
                    return true;
                }
                for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
                    if (target.second > 0) { // 记录到达机场是否飞过了
                        result.push_back(target.first);
                        target.second--;
                        if (backtracking(ticketNum, result)) return true;
                        result.pop_back();
                        target.second++;
                    }
                }
                return false;
            }
        public:
            vector<string> findItinerary(vector<vector<string>>& tickets) {
                targets.clear();
                vector<string> result;
                for (const vector<string>& vec : tickets) {
                    targets[vec[0]][vec[1]]++; // 记录映射关系
                }
                result.push_back("JFK"); // 起始机场
                backtracking(tickets.size(), result);
                return result;
            }
    };
    ~~~