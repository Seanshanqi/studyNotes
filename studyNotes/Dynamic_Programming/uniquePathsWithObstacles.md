# [63. ��ͬ·�� II](https://leetcode.cn/problems/unique-paths-ii/)
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������

���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����

�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��

![](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)  
���룺obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]  
�����2  
���ͣ�3x3 ��������м���һ���ϰ��  
�����Ͻǵ����½�һ���� 2 ����ͬ��·����  
1. ���� -> ���� -> ���� -> ����  
2. ���� -> ���� -> ���� -> ����  

## ˼·
����������62.��ͬ·�� (opens new window)���������ϰ���

��һ�νӴ�������Ŀ��ͬѧ���ܻ��е��£������ϰ��ˣ�Ӧ����ô���أ�

62.��ͬ·�� (opens new window)�������Ѿ���ϸ������û���ϰ�����������ϰ��Ļ�����ʵ���Ǳ�Ƕ�Ӧ��dp table��dp���飩���ֳ�ʼֵ(0)�Ϳ����ˡ�

�����岿����

ȷ��dp���飨dp table���Լ��±�ĺ���
dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·����

ȷ�����ƹ�ʽ
���ƹ�ʽ��62.��ͬ·��һ����dp[i][j] = dp[i - 1][j] + dp[i][j - 1]��

��������Ҫע��һ�㣬��Ϊ�����ϰ���(i, j)��������ϰ��Ļ�Ӧ�þͱ��ֳ�ʼ״̬����ʼ״̬Ϊ0����

���Դ���Ϊ��
~~~c
if (obstacleGrid[i][j] == 0) { // ��(i, j)û���ϰ���ʱ�����Ƶ�dp[i][j]
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
}
~~~
dp������γ�ʼ��
��62.��ͬ·�� (opens new window)��ͬ·�������Ǹ������µĳ�ʼ����
~~~c
vector<vector<int>> dp(m, vector<int>(n, 0)); // ��ʼֵΪ0
for (int i = 0; i < m; i++) dp[i][0] = 1;
for (int j = 0; j < n; j++) dp[0][j] = 1;
~~~
��Ϊ��(0, 0)��λ�õ�(i, 0)��·��ֻ��һ��������dp[i][0]һ��Ϊ1��dp[0][j]Ҳͬ��

�����(i, 0) �����������ϰ�֮���ϰ�֮�󣨰����ϰ��������߲�����λ���ˣ������ϰ�֮���dp[i][0]Ӧ�û��ǳ�ʼֵ0��

���Ա����ʼ������Ϊ��
~~~c
vector<vector<int>> dp(m, vector<int>(n, 0));
for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
~~~
ע�������forѭ������ֹ������һ������obstacleGrid[i][0] == 1�������ֹͣdp[i][0]�ĸ�ֵ1�Ĳ�����dp[0][j]ͬ��

ȷ������˳��
�ӵݹ鹫ʽdp[i][j] = dp[i - 1][j] + dp[i][j - 1] �п��Կ�����һ���Ǵ�����һ��һ�������������֤�Ƶ�dp[i][j]��ʱ��dp[i - 1][j] �� dp[i][j - 1]һ��������ֵ��

�������£�
~~~c
for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 1) continue;
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
}
~~~

�����岿�ַ�����ϣ���ӦC++�������£�
~~~c
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
	if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //����������յ�������ϰ���ֱ�ӷ���0
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
~~~
ʱ�临�Ӷȣ�O(n �� m)��n��m �ֱ�ΪobstacleGrid ���ȺͿ��
�ռ临�Ӷȣ�O(n �� m)