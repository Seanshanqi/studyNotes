# [��������](https://leetcode.cn/problems/maximum-binary-tree/)
����һ�����ظ����������� nums �� �������� ������������㷨�� nums �ݹ�ع���:

����һ�����ڵ㣬��ֵΪ nums �е����ֵ��
�ݹ�������ֵ ��� �� ������ǰ׺�� ������������
�ݹ�������ֵ �ұ� �� �������׺�� ������������
���� nums ������ �������� ��

## ˼·
������һ����õ���ǰ���������Ϊ�ȹ����м�ڵ㣬Ȼ��ݹ鹹������������������

ȷ���ݹ麯���Ĳ����ͷ���ֵ
����������Ǵ��Ԫ�ص����飬���ظ����鹹��Ķ�������ͷ��㣬����������ָ��ڵ��ָ�롣

�������£�
~~~c
TreeNode* constructMaximumBinaryTree(vector<int>& nums)
~~~
ȷ����ֹ����
��Ŀ��˵������������Сһ���Ǵ��ڵ���1�ģ��������ǲ��ÿ���С��1���������ô���ݹ������ʱ���������������СΪ1��˵����������Ҷ�ӽڵ��ˡ�

��ôӦ�ö���һ���µĽڵ㣬��������������ֵ�����µĽڵ㣬Ȼ�󷵻�����ڵ㡣 ���ʾһ�������С��1��ʱ�򣬹�����һ���µĽڵ㣬�����ء�

�������£�
~~~c
TreeNode* node = new TreeNode(0);
if (nums.size() == 1) {
    node->val = nums[0];
    return node;
}
~~~
ȷ������ݹ���߼�
��������������

��Ҫ�ҵ�����������ֵ�Ͷ�Ӧ���±꣬ ����ֵ������ڵ㣬�±�������һ���ָ����顣
�������£�
~~~c
int maxValue = 0;
int maxValueIndex = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > maxValue) {
        maxValue = nums[i];
        maxValueIndex = i;
    }
}
TreeNode* node = new TreeNode(0);
node->val = maxValue;
~~~
���ֵ���ڵ��±������� ����������
����Ҫ�ж�maxValueIndex > 0����ΪҪ��֤������������һ����ֵ��

�������£�
~~~c
if (maxValueIndex > 0) {
    vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
    node->left = constructMaximumBinaryTree(newVec);
}
~~~
���ֵ���ڵ��±������� ����������
�ж�maxValueIndex < (nums.size() - 1)��ȷ��������������һ����ֵ��

�������£�
~~~c
if (maxValueIndex < (nums.size() - 1)) {
    vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
    node->right = constructMaximumBinaryTree(newVec);
}
~~~
����������£�����ϸע�ͣ�
~~~c
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        // �ҵ�����������ֵ�Ͷ�Ӧ���±�
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;
        // ���ֵ���ڵ��±������� ����������
        if (maxValueIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        // ���ֵ���ڵ��±������� ����������
        if (maxValueIndex < (nums.size() - 1)) {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};
~~~
���ϴ���Ƚ����࣬Ч��Ҳ���ߣ�ÿ�λ�Ҫ�и��ʱ��ÿ�ζ�Ҫ�����µ�vector��Ҳ�������飩�����߼��Ƚ�������
�Ż������Ϊ��
~~~c
class Solution {
private:
    // ������ҿ�����[left, right)�����������
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        // �ָ���±꣺maxValueIndex
        int maxValueIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        // ����ҿ���[left, maxValueIndex)
        root->left = traversal(nums, left, maxValueIndex);

        // ����ҿ���[maxValueIndex + 1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
~~~