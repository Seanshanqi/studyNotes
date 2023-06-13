# [Ŀ���](https://leetcode.cn/problems/target-sum/)
����һ���������� nums ��һ������ target ��

�������е�ÿ������ǰ���� '+' �� '-' ��Ȼ�������������������Թ���һ�� ����ʽ ��

���磬nums = [2, 1] �������� 2 ֮ǰ���� '+' ���� 1 ֮ǰ���� '-' ��Ȼ���������õ�����ʽ "+2-1" ��
���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ����ʽ ����Ŀ��
ʾ�� 1��  

���룺nums = [1,1,1,1,1], target = 3  
�����5  
���ͣ�һ���� 5 �ַ���������Ŀ���Ϊ 3 ��  
-1 + 1 + 1 + 1 + 1 = 3  
+1 - 1 + 1 + 1 + 1 = 3  
+1 + 1 - 1 + 1 + 1 = 3  
+1 + 1 + 1 - 1 + 1 = 3  
+1 + 1 + 1 + 1 - 1 = 3  
##   ��̬�滮
���ת��Ϊ01���������ء�

����ӷ����ܺ�Ϊx����ô������Ӧ���ܺ;���sum - x��

��������Ҫ����� x - (sum - x) = target

x = (target + sum) / 2

��ʱ�����ת��Ϊ��װ������Ϊx�ı������м��ַ�����

�����x������bagSize��Ҳ�������Ǻ���Ҫ��ı���������

��ҿ���(target + sum) / 2 Ӧ�õ��ļ���Ĺ���������ȡ����û��Ӱ�졣

��ô���ľͶ��ˣ�����sum ��5��S��2�Ļ���ʵ�����޽�ģ����ԣ�
~~~c
��C++�����У������S ������Ŀ������ target��
if ((S + sum) % 2 == 1) return 0; // ��ʱû�з���
ͬʱ��� S�ľ���ֵ�Ѿ�����sum����ôҲ��û�з����ġ�

��C++�����У������S ������Ŀ������ target��
if (abs(S) > sum) return 0; // ��ʱû�з���
~~~
�ٻع鵽01�������⣬Ϊʲô��01�����أ�

��Ϊÿ����Ʒ����Ŀ�е�1��ֻ��һ�Σ�

��κ�֮ǰ�����ı������ⲻһ���ˣ�֮ǰ����������Ϊj�ı����������װ���١�

��������װ���м��ַ�������ʵ�����һ����������ˡ�

ȷ��dp�����Լ��±�ĺ���
dp[j] ��ʾ������j������j����ô���ݻ��İ�����dp[j]�ַ���

��ʵҲ����ʹ�ö�άdp��������Ȿ�⣬dp[i][j]��ʹ�� �±�Ϊ[0, i]��nums[i]�ܹ�����j������j����ô�������İ�����dp[i][j]�ַ�����

�����Ҷ���ͳһʹ��һά������н��⣬ ��ά��Ϊһά���������飩����ʵ������һ�㿽��������������ڶ�̬�滮������01�������⣬����˽���Щ�����������飩 (opens new window)Ҳ�н��ܡ�

ȷ�����ƹ�ʽ
����Щ��Դ�����Ƴ�dp[j]�أ�

ֻҪ�㵽nums[i]���ճ�dp[j]����dp[j - nums[i]] �ַ�����

���磺dp[j]��j Ϊ5��

�Ѿ���һ��1��nums[i]�� �Ļ����� dp[4]�ַ��� �ճ� ����Ϊ5�ı�����
�Ѿ���һ��2��nums[i]�� �Ļ����� dp[3]�ַ��� �ճ� ����Ϊ5�ı�����
�Ѿ���һ��3��nums[i]�� �Ļ����� dp[2]�з��� �ճ� ����Ϊ5�ı���
�Ѿ���һ��4��nums[i]�� �Ļ����� dp[1]�з��� �ճ� ����Ϊ5�ı���
�Ѿ���һ��5 ��nums[i]���Ļ����� dp[0]�з��� �ճ� ����Ϊ5�ı���
��ô����dp[5]�ж��ٷ����أ�Ҳ���ǰ� ���е� dp[j - nums[i]] �ۼ�������

���������������Ĺ�ʽ�������������֣�

dp[j] += dp[j - nums[i]]
�����ʽ�ں����ڽ��ⱳ�����������������ʱ�򻹻��õ���

dp������γ�ʼ��
�ӵ��ƹ�ʽ���Կ������ڳ�ʼ����ʱ��dp[0] һ��Ҫ��ʼ��Ϊ1����Ϊdp[0]���ڹ�ʽ��һ�е��ƽ������Դ�����dp[0]��0�Ļ������ƽ��������0��

������¼�ѿ�����Ϊ��dp���鶨����˵ dp[0] Ӧ����0��Ҳ��¼����Ϊdp[0]Ӧ����1��

��ʵ��ҪӲȥ�������ĺ��壬�۾Ͱ� dp[0]��������뱾�⿴��Ӧ�õ��ڶ��١�

�������[0] ��target = 0����ô bagSize = (target + sum) / 2 = 0�� dp[0]ҲӦ����1�� Ҳ����˵���������Ԫ�� 0 ǰ�����۷żӷ����Ǽ��������� 1 �ַ�����

���Ա�������Ӧ�ó�ʼ�� dp[0] Ϊ 1��

������ͬѧ���ˣ��� ����� ����[0,0,0,0,0] target = 0 �ء�

��ʵ ��ʱ���յ�dp[0] = 32��Ҳ����������� �Ӽ�������������������dp[0]�Ǳ�dp[0]��dp[0]�����32�����������Ϊdp[0] = 1 �ۼ������ġ�

dp[j]�����±��Ӧ����ֵҲӦ�ó�ʼ��Ϊ0���ӵ��ƹ�ʽҲ���Կ�����dp[j]Ҫ��֤��0�ĳ�ʼֵ��������ȷ����dp[j - nums[i]]�Ƶ�������

ȷ������˳��
�ڶ�̬�滮������01�������⣬����˽���Щ�����������飩 (opens new window)�У����ǽ�������01��������һάdp�ı�����nums������ѭ����target����ѭ��������ѭ������

C++�������£�
~~~c
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (abs(S) > sum) return 0; // ��ʱû�з���
        if ((S + sum) % 2 == 1) return 0; // ��ʱû�з���
        int bagSize = (S + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
~~~
ʱ�临�Ӷȣ�O(n �� m)��nΪ����������mΪ��������  
�ռ临�Ӷȣ�O(m)��mΪ��������  