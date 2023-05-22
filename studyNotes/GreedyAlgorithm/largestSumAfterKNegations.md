# [K ��ȡ������󻯵������](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)
����һ���������� nums ��һ������ k �������·����޸ĸ����飺  

ѡ��ĳ���±� i ���� nums[i] �滻Ϊ -nums[i] ��  
�ظ��������ǡ�� k �Ρ����Զ��ѡ��ͬһ���±� i ��  

�����ַ�ʽ�޸�����󣬷������� ���ܵ����� ��  

 

ʾ�� 1��  

���룺nums = [4,2,3], k = 1  
�����5  
���ͣ�ѡ���±� 1 ��nums ��Ϊ [4,-2,3] ��  
˼·
����˼·��ʵ�ȽϺ����ˣ���ο��������������أ�

̰�ĵ�˼·���ֲ����ţ��þ���ֵ��ĸ�����Ϊ��������ǰ��ֵ�ﵽ����������ţ���������ʹﵽ���

�ֲ����ſ����Ƴ�ȫ�����š�

��ô�����������ת��Ϊ�����ˣ�K��Ȼ����0����ʱ��������һ���������������У����ת��K���������� ����� �ﵽ���

��ô����һ��̰�ģ��ֲ����ţ�ֻ����ֵ��С�����������з�ת����ǰ��ֵ�Ϳ��Դﵽ�����������������{5, 3, 1}����ת1 �õ�-1 �� ��ת5�õ���-5 ����ˣ���ȫ�����ţ����� ����� �ﵽ���

��Ȼ�����Ŀ�������ʱ�򣬿��ܶ�����ȥ��ʲô̰���㷨��һ����������AC�ˡ�

��������ʵ��Ϊ�˸����չ�ֳ��� ��������Һ��Ե�̰��˼·����ôһ�����⣬����������̰�ģ�

��ô����Ľ��ⲽ��Ϊ��

��һ���������鰴�վ���ֵ��С�Ӵ�С����ע��Ҫ���վ���ֵ�Ĵ�С
�ڶ�������ǰ���������������������Ϊ������ͬʱK--
�����������K������0����ô����ת����ֵ��С��Ԫ�أ���K����
���Ĳ������
��ӦC++�������£�
~~~c
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // ��һ��
        for (int i = 0; i < A.size(); i++) { // �ڶ���
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // ������
        int result = 0;
        for (int a : A) result += a;        // ���Ĳ�
        return result;
    }
};
~~~
## �ܽ�
̰�ĵ���Ŀ����������������˼򵥵���ʼ���ɣ���������Ӧ����ô��ô����Ҳ�����㷨������Ϊ�ⲻ��̰�ģ�



���û��̰�ĵ�˼����ʽ���ֲ����ţ�ȫ�����ţ�������������̰�ļ���ƾ�о�����̰������ֱ�Ӳ���������ʵ�����Ͷ�������̰�ĵ�˼����ʽ�ˡ�

������֪����̰�ļ��⣬ҲҪ��̰�ĵ�˼����ʽ�����⣬��������������о����а�����