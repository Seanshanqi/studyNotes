[108.����������ת��Ϊ����������](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)
����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������

�߶�ƽ�� ��������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������  
![](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)  
���룺nums = [-10,-3,0,5,9]  
�����[0,-3,9,-10,null,5]  
���ͣ�[0,-10,5,null,-3,null,9] Ҳ������Ϊ��ȷ�𰸣�  
![](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)  
�ݹ�
�ݹ���������

ȷ���ݹ麯������ֵ�������
ɾ���������ڵ㣬���Ӷ������ڵ㣬�����õݹ麯���ķ���ֵ����ɣ������ǱȽϷ���ġ�

���Ŵ�������ϸ���˶��������������еĲ������ (opens new window)�Ͷ��������������е�ɾ������ (opens new window)��һ����Եݹ麯������ֵ���������ид���

��ô����Ҫ�������������Ȼ�õݹ麯���ķ���ֵ�������нڵ�����Һ��ӡ�

�����������������Ǵ������飬Ȼ��������±�left�����±�right�������ڶ�����������������ǳ��� (opens new window)��������ڹ����������ʱ������Ҫ���¶��������������飬�������±�������ԭ���顣

���Դ������£�
~~~c
// ����ұ�����[left, right]
TreeNode* traversal(vector<int>& nums, int left, int right)
~~~
����ע�⣬�����ﶨ���������ұ����䣬�ڲ��Ϸָ�Ĺ����У�Ҳ��������ұյ����䣬�����漰�����ǽ�����ѭ����������

�ڶ�����������������ǳ��� (opens new window)��35.��������λ�� (opens new window)��59.��������II (opens new window)����ϸ����ѭ����������

ȷ���ݹ���ֹ����
���ﶨ���������ұյ����䣬���Ե����� left > right��ʱ�򣬾��ǿսڵ��ˡ�

�������£�
~~~c
if (left > right) return nullptr;
~~~
ȷ������ݹ���߼�
����ȡ�����м�Ԫ�ص�λ�ã�����д��int mid = (left + right) / 2;����ôд��ʵ��һ�����⣬������ֵԽ�磬����left��right�������int����ô������Խ���ˣ��ڶ��ַ� (opens new window)��������Ҫע�⣡

���Կ�����ôд��int mid = left + ((right - left) / 2);

������leetcode�Ĳ������ݲ�����Խ�磬������ôд�����ԡ�����Ҫ�������ʶ��

ȡ���м�λ�ã��Ϳ�ʼ���м�λ�õ�Ԫ�ع���ڵ㣬���룺TreeNode* root = new TreeNode(nums[mid]);��

���Ż������䣬root�����ӽ�ס��һ��������Ĺ���ڵ㣬�Һ��ӽ�ס��һ�������乹��Ľڵ㡣

��󷵻�root�ڵ㣬����ݹ�����������£�
~~~c
int mid = left + ((right - left) / 2);
TreeNode* root = new TreeNode(nums[mid]);
root->left = traversal(nums, left, mid - 1);
root->right = traversal(nums, mid + 1, right);
return root;
~~~
����int mid = left + ((right - left) / 2);��д���൱����������鳤��Ϊż�����м�λ��������Ԫ�أ�ȡ����ߵġ�

�ݹ�����������£�
~~~c
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};
~~~
ע�⣺�ڵ���traversal��ʱ�����left��rightΪʲô��0��nums.size() - 1����Ϊ���������Ϊ����ұա�