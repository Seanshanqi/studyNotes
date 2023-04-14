[108.将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。  
![](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)  
输入：nums = [-10,-3,0,5,9]  
输出：[0,-3,9,-10,null,5]  
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：  
![](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)  
递归
递归三部曲：

确定递归函数返回值及其参数
删除二叉树节点，增加二叉树节点，都是用递归函数的返回值来完成，这样是比较方便的。

相信大家如果仔细看了二叉树：搜索树中的插入操作 (opens new window)和二叉树：搜索树中的删除操作 (opens new window)，一定会对递归函数返回值的作用深有感触。

那么本题要构造二叉树，依然用递归函数的返回值来构造中节点的左右孩子。

再来看参数，首先是传入数组，然后就是左下标left和右下标right，我们在二叉树：构造二叉树登场！ (opens new window)中提过，在构造二叉树的时候尽量不要重新定义左右区间数组，而是用下标来操作原数组。

所以代码如下：
~~~c
// 左闭右闭区间[left, right]
TreeNode* traversal(vector<int>& nums, int left, int right)
~~~
这里注意，我这里定义的是左闭右闭区间，在不断分割的过程中，也会坚持左闭右闭的区间，这又涉及到我们讲过的循环不变量。

在二叉树：构造二叉树登场！ (opens new window)，35.搜索插入位置 (opens new window)和59.螺旋矩阵II (opens new window)都详细讲过循环不变量。

确定递归终止条件
这里定义的是左闭右闭的区间，所以当区间 left > right的时候，就是空节点了。

代码如下：
~~~c
if (left > right) return nullptr;
~~~
确定单层递归的逻辑
首先取数组中间元素的位置，不难写出int mid = (left + right) / 2;，这么写其实有一个问题，就是数值越界，例如left和right都是最大int，这么操作就越界了，在二分法 (opens new window)中尤其需要注意！

所以可以这么写：int mid = left + ((right - left) / 2);

但本题leetcode的测试数据并不会越界，所以怎么写都可以。但需要有这个意识！

取了中间位置，就开始以中间位置的元素构造节点，代码：TreeNode* root = new TreeNode(nums[mid]);。

接着划分区间，root的左孩子接住下一层左区间的构造节点，右孩子接住下一层右区间构造的节点。

最后返回root节点，单层递归整体代码如下：
~~~c
int mid = left + ((right - left) / 2);
TreeNode* root = new TreeNode(nums[mid]);
root->left = traversal(nums, left, mid - 1);
root->right = traversal(nums, mid + 1, right);
return root;
~~~
这里int mid = left + ((right - left) / 2);的写法相当于是如果数组长度为偶数，中间位置有两个元素，取靠左边的。

递归整体代码如下：
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
注意：在调用traversal的时候传入的left和right为什么是0和nums.size() - 1，因为定义的区间为左闭右闭。