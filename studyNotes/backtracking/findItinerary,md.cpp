[332.���°����г�]()

����һ�ݺ����б� tickets ������ tickets[i] = [fromi, toi] ��ʾ�ɻ������ͽ���Ļ����ص㡣����Ը��г̽������¹滮����

������Щ��Ʊ������һ���� JFK������Ϲ��ʻ��������������������Ը��г̱���� JFK ��ʼ��������ڶ�����Ч���г̣����㰴�ֵ����򷵻���С���г���ϡ�

���磬�г�["JFK", "LGA"] ��["JFK", "LGB"] ��Ⱦ͸�С���������ǰ��
ʾ����![](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)  

�ٶ����л�Ʊ���ٴ���һ�ֺ�����г̡������еĻ�Ʊ ���붼��һ�� �� ֻ����һ�Ρ�
���룺tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
�����["JFK", "MUC", "LHR", "SFO", "SJC"]

�ü�¼ӳ���ϵ
�ж��ֽⷨ����ĸ��ǰ����ǰ�棬��θü�¼ӳ���ϵ�� ��

һ������ӳ��������������֮��Ҫ����ĸ�����У�һ������ӳ��������������ʹ��std::unordered_map������ö������֮������˳��Ļ���������std::map ����std::multimap ���� std::multiset��

�����map �� set ��ʵ�ֻ��Ʋ�̫�˽⣬Ҳ�����Ϊʲô map��multimap���������ͬѧ�����Կ���ƪ���¹��ڹ�ϣ������˽���Щ��(opens new window)��

�������ӳ���ϵ���Զ���Ϊ unordered_map<string, multiset<string>> targets ���� unordered_map<string, map<string, int>> targets��

�������£�

unordered_map<string, multiset> targets��unordered_map<��������, ��������ļ���> targets

unordered_map<string, map<string, int>> targets��unordered_map<��������, map<�������, �������>> targets

�������ṹ����ѡ���˺��ߣ���Ϊ���ʹ��unordered_map<string, multiset<string>> targets ����multiset��ʱ�򣬲���ɾ��Ԫ�أ�һ��ɾ��Ԫ�أ���������ʧЧ�ˡ�

��˵һ��Ϊʲôһ��Ҫ��ɾԪ���أ����翪ƪ�Ҹ�����ͼ����ʾ�����������͵�������ǻ��ظ��ģ������Ĺ���û��ʱɾ��Ŀ�Ļ����ͻ���ѭ����

���������Ĺ����о���Ҫ���ϵ�ɾmultiset���Ԫ�أ���ô�Ƽ�ʹ��unordered_map<string, map<string, int>> targets��

�ڱ��� unordered_map<��������, map<�������, �������>> targets�Ĺ����У�����ʹ��"�������"����ֶε���������Ӧ������������ǵ�������Ƿ�ʹ�ù��ˡ�

�������������������㣬˵��Ŀ�ĵػ����Էɣ���������������������˵��Ŀ�ĵز��ܷ��ˣ������öԼ�����ɾ��Ԫ�ػ�������Ԫ�صĲ�����

�൱��˵�Ҳ�ɾ���Ҿ���һ����ǣ�

#���ݷ�
�����Ŀ��ʹ�û��ݷ�����ô���水�����ܽ�Ļ���ģ������
~~~c
void backtracking(����) {
    if (��ֹ����) {
        ��Ž��;
        return;
    }

    for (ѡ�񣺱��㼯����Ԫ�أ����нڵ㺢�ӵ��������Ǽ��ϵĴ�С��) {
        ����ڵ�;
        backtracking(·����ѡ���б�); // �ݹ�
        ���ݣ�����������
    }
}
~~~

��ʼ�������������⣺

�ݹ麯������
�ڽ���ӳ���ϵ��ʱ���Ѿ������ˣ�ʹ��unordered_map<string, map<string, int>> targets; ����¼�����ӳ���ϵ���Ҷ���Ϊȫ�ֱ�����

��Ȼ�Ѳ����Ž������ﴫ��ȥҲ�ǿ��Եģ����Ǿ������ƺ���������ĳ��ȡ�

�����ﻹ��ҪticketNum����ʾ�ж��ٸ����ࣨ��ֹ���������ϣ���

�������£�
~~~c
// unordered_map<��������, map<�������, �������>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result) {
    ~~~
        ע�⺯������ֵ���õ���bool��

        ����֮ǰ��������㷨��ʱ��һ�㺯������ֵ����void�����Ϊʲô��bool�أ�

        ��Ȼ�����targets��result����Ҫ��ʼ�����������£�
        ~~~c
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // ��¼ӳ���ϵ
        }
    result.push_back("JFK"); // ��ʼ����
    ~~~
        �ݹ���ֹ����
        ����Ŀ�е�ʾ��Ϊ�������� : [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]] ��������4�����࣬��ôֻҪ�ҳ�һ���г̣��г���Ļ���������5�Ϳ����ˡ�

        ������ֹ�����ǣ����ǻ��ݱ����Ĺ����У������Ļ�������������ﵽ�ˣ��������� + 1������ô���Ǿ��ҵ���һ���г̣������к��മ��һ���ˡ�

        �������£�
        ~~~c
        if (result.size() == ticketNum + 1) {
            return true;
        }
    ~~~
        �Ѿ���ϰ�߻��ݷ������ͬѧ����Ҷ�ӽڵ���ϰ���Ե���Ҫ�ռ�����������ֲ�����Ҫ�������result�൱�� �����㷨��������ܺͣ�(opens new window)�е�path��Ҳ���Ǳ����result���Ǽ�¼·���ģ���һ�����������µ����������߼���result�����Ԫ���ˡ�

        �����������߼�
        ���ݵĹ����У���α���һ����������Ӧ�����л����أ�

        ����ո�˵������ѡ��ӳ�亯����ʱ�򣬲���ѡ��unordered_map<string, multiset<string>> targets�� ��Ϊһ����Ԫ����ɾmultiset�ĵ������ͻ�ʧЧ����Ȼ������ţ�Ƶ�����ɾ��Ԫ�ص���������ʧЧ������Ͳ��������ˡ�

        ����˵�����Ҫ�ҵ�һ�������ݽ�����������������һ�Ҫ������ɾԪ�أ�������������ʧЧ��

        ������ѡ����unordered_map<string, map<string, int>> targets ��������֮���ӳ�䡣

        �����������£�
        ~~~c
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) { // ��¼��������Ƿ�ɹ���
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
    ~~~
        ���Կ��� ͨ��unordered_map<string, map<string, int>> targets���int�ֶ����ж� ���������Ļ����Ƿ�ʹ�ù�������������ֱ��ȥɾԪ�ء�

        ������ϣ���ʱ����C++�������£�
        ~~~c
        class Solution {
        private:
            // unordered_map<��������, map<�������, �������>> targets
            unordered_map<string, map<string, int>> targets;
            bool backtracking(int ticketNum, vector<string>& result) {
                if (result.size() == ticketNum + 1) {
                    return true;
                }
                for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
                    if (target.second > 0) { // ��¼��������Ƿ�ɹ���
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
                    targets[vec[0]][vec[1]]++; // ��¼ӳ���ϵ
                }
                result.push_back("JFK"); // ��ʼ����
                backtracking(tickets.size(), result);
                return result;
            }
    };
    ~~~