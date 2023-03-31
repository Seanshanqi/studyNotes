# [106. �����������������й��������](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

���������������� inorder �� postorder ������ inorder �Ƕ���������������� postorder ��ͬһ�����ĺ�����������㹹�첢������� ������ ��
## ˼·
��һ������������СΪ��Ļ���˵���ǿսڵ��ˡ�

�ڶ����������Ϊ�գ���ôȡ�����������һ��Ԫ����Ϊ�ڵ�Ԫ�ء�

���������ҵ������������һ��Ԫ�������������λ�ã���Ϊ�и��

���Ĳ����и��������飬�г���������������������� ��˳���㷴�ˣ�һ���������������飩

���岽���и�������飬�гɺ���������ͺ���������

���������ݹ鴦���������������

�ɴ�д��������
~~~c
TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {

    // ��һ��
    if (postorder.size() == 0) return NULL;

    // �ڶ�������������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    // Ҷ�ӽڵ�
    if (postorder.size() == 1) return root;

    // �����������и��
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
    }

    // ���Ĳ����и��������飬�õ� ���������������������
    // ���岽���и�������飬�õ� ����������ͺ���������

    // ������
    root->left = traversal(����������, ����������);
    root->right = traversal(����������, ����������);

    return root;
}
~~~

����Ҫ�и��������飬Ϊʲô���и����������أ�

�и���ں�����������һ��Ԫ�أ����������Ԫ�����и���������ģ����Ա�Ҫ���и��������顣

����������ԱȽϺ��У��ҵ��и�㣨������������һ��Ԫ�أ������������λ�ã�Ȼ���и���´������Ҽ������ҿ���ԭ��
~~~c
// �ҵ�����������и��
int delimiterIndex;
for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
    if (inorder[delimiterIndex] == rootValue) break;
}

// ����ҿ����䣺[0, delimiterIndex)
vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
// [delimiterIndex + 1, end)
vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );
~~~

��������Ҫ�и���������ˡ�

���Ⱥ�����������һ��Ԫ��ָ������Ҫ�ˣ������и�� Ҳ�� ��ǰ�������м�ڵ��Ԫ�أ��Ѿ����ˡ�

����������и����ô�ң�

��������û����ȷ���и�Ԫ�������������и����������������ȷ���и�㣬�и�����ҷֿ��Ϳ����ˡ�

��ʱ��һ�����صĵ㣬�������������Сһ���Ǻͺ�������Ĵ�С��ͬ�ģ����Ǳ�Ȼ����

�����������Ƕ��г�������������������������ˣ���ô��������Ϳ��԰�������������Ĵ�С���и�г������������Һ������顣

�������£�
~~~c
// postorder ����ĩβԪ�أ���Ϊ���Ԫ�ؾ����м�ڵ㣬�Ѿ��ù���
postorder.resize(postorder.size() - 1);

// ����ҿ���ע������ʹ���������������С��Ϊ�и�㣺[0, leftInorder.size)
vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
// [leftInorder.size(), end)
vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
~~~
��ʱ�����������г�����������������������飬���������и�������������Һ������顣

���������Եݹ��ˣ��������£�

root->left = traversal(leftInorder, leftPostorder);
root->right = traversal(rightInorder, rightPostorder);
�����������£�

#C++��������
~~~c
class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // ��������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // Ҷ�ӽڵ�
        if (postorder.size() == 1) return root;

        // �ҵ�����������и��
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // �и���������
        // ����ҿ����䣺[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // postorder ����ĩβԪ��
        postorder.resize(postorder.size() - 1);

        // �и��������
        // ��Ȼ����ҿ���ע������ʹ���������������С��Ϊ�и��
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};
~~~