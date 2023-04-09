# [�����������е�����](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)
����һ�����ظ�ֵ�Ķ�����������BST���ĸ��ڵ� root ���ҳ������� BST �е����� ��������������Ƶ����ߵ�Ԫ�أ���

��������в�ֹһ�����������԰� ����˳�� ���ء�

�ٶ� BST �������¶��壺

����������������ڵ��ֵ С�ڵ��� ��ǰ�ڵ��ֵ  
����������������ڵ��ֵ ���ڵ��� ��ǰ�ڵ��ֵ  
�����������������Ƕ���������  
![](https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg)
˼·
�����Ŀ�أ��ݹ鷨�Ҵ�����ά��������

����������Ƕ����������Ļ���Ӧ����ô���⣬�Ƕ�������������Ӧ����ν��⣬���ַ�ʽ��һ���Ƚϣ����Լ����ҶԶ���������⡣

#�ݹ鷨
#������Ƕ���������
������Ƕ�������������ֱ�۵ķ���һ���ǰ�������������ˣ���mapͳ��Ƶ�ʣ���Ƶ���Ÿ������ȡǰ���Ƶ��Ԫ�صļ��ϡ�

���岽�����£�

������������ˣ���mapͳ��Ƶ��
������ǰ�к������ֱ���Ҳ����Ҫ����Ϊ����Ҫȫ����һ�飬��ô�����������У����������ûë����

�������ǰ��������������£�

// map<int, int> key:Ԫ�أ�value:����Ƶ��
void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // ǰ�����
    if (cur == NULL) return ;
    map[cur->val]++; // ͳ��Ԫ��Ƶ��
    searchBST(cur->left, map);
    searchBST(cur->right, map);
    return ;
}
��ͳ�Ƶĳ����ĳ���Ƶ�ʣ���map�е�value���Ÿ���
�е�ͬѧ���ܿ�����ֱ�Ӷ�map�е�value���򣬻�����������C++�����ʹ��std::map����std::multimap���Զ�key���򣬵����ܶ�value����

����Ҫ��mapת�����鼴vector���ٽ������򣬵�Ȼvector����ŵ�Ҳ��pair<int, int>���͵����ݣ���һ��intΪԪ�أ��ڶ���intΪ����Ƶ�ʡ�

�������£�

~~~c
bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second; // ����Ƶ�ʴӴ�С����
}

vector<pair<int, int>> vec(map.begin(), map.end());
sort(vec.begin(), vec.end(), cmp); // ��Ƶ���Ÿ���
~~~
ȡǰ���Ƶ��Ԫ��
��ʱ����vector���Ѿ��Ǵ���Ű���Ƶ���ź����pair����ô��ǰ���Ƶ��Ԫ��ȡ�����Ϳ����ˡ�

�������£�
~~~c
result.push_back(vec[0].first);
for (int i = 1; i < vec.size(); i++) {
    // ȡ��ߵķŵ�result������
    if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
    else break;
}
return result;
~~~
����C++�������£�
~~~c
class Solution {
private:

void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // ǰ�����
    if (cur == NULL) return ;
    map[cur->val]++; // ͳ��Ԫ��Ƶ��
    searchBST(cur->left, map);
    searchBST(cur->right, map);
    return ;
}
bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map; // key:Ԫ�أ�value:����Ƶ��
        vector<int> result;
        if (root == NULL) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp); // ��Ƶ���Ÿ���
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            // ȡ��ߵķŵ�result������
            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};
~~~
�����������û��˵�Ƕ����������Ļ�����ô�Ͱ��������˼·д��

#�Ƕ���������
��Ȼ���������������������������ġ�
��������������£�
~~~c
void searchBST(TreeNode* cur) {
    if (cur == NULL) return ;
    searchBST(cur->left);       // ��
    ������ڵ㣩                // ��
    searchBST(cur->right);      // ��
    return ;
}
~~~
�������������Ԫ�س���Ƶ�ʣ���ͷ��������ôһ������������Ԫ�����Ƚϣ�Ȼ��Ͱѳ���Ƶ����ߵ�Ԫ������Ϳ����ˡ�

�ؼ��������������ϵĻ����ø㣬��������ô���أ�

��Ϳ�������Ĳ����ˡ�

�ڶ�����������������С���Բ� (opens new window)�����Ǿ�ʹ����preָ���curָ��ļ��ɣ�����������ˡ�

Ūһ��ָ��ָ��ǰһ���ڵ㣬����ÿ��cur����ǰ�ڵ㣩���ܺ�pre��ǰһ���ڵ㣩���Ƚϡ�

���ҳ�ʼ����ʱ��pre = NULL��������preΪNULLʱ�����Ǿ�֪�����ǱȽϵĵ�һ��Ԫ�ء�

�������£�
~~~c
if (pre == NULL) { // ��һ���ڵ�
    count = 1; // Ƶ��Ϊ1
} else if (pre->val == cur->val) { // ��ǰһ���ڵ���ֵ��ͬ
    count++;
} else { // ��ǰһ���ڵ���ֵ��ͬ
    count = 1;
}
pre = cur; // ������һ���ڵ�
~~~
��ʱ���������ˣ���ΪҪ�����Ƶ�ʵ�Ԫ�ؼ��ϣ�ע���Ǽ��ϣ�����һ��Ԫ�أ������ж��������������������ϴ��һ����ô�죿

Ӧ�����ȱ���һ�����飬�ҳ����Ƶ�ʣ�maxCount����Ȼ�������±���һ������ѳ���Ƶ��ΪmaxCount��Ԫ�طŽ����ϡ�����Ϊ�����ж����

���ַ�ʽ�������������顣

��ô���Ǳ���������������������������������Ҳ�ǿ��Եġ�

��������ʵֻ��Ҫ����һ�ξͿ����ҵ����е�������

��ô���ֻ����һ���أ�

��� Ƶ��count ���� maxCount�����Ƶ�ʣ�����ȻҪ�����Ԫ�ؼ��뵽������У����´���Ϊresult���飩���������£�
~~~c
if (count == maxCount) { // ��������ֵ��ͬ���Ž�result��
    result.push_back(cur->val);
}
~~~
�ǲ��Ǹо����������⣬result��ô�����׾Ͱ�Ԫ�طŽ�ȥ���أ���һ�����maxCount��ʱ�������������Ƶ���ء�

��������Ҫ�����²�����

Ƶ��count ���� maxCount��ʱ�򣬲���Ҫ����maxCount������Ҫ��ս���������´���Ϊresult���飩����Ϊ�����֮ǰ��Ԫ�ض�ʧЧ�ˡ�
~~~c
if (count > maxCount) { // ��������������ֵ
    maxCount = count;   // �������Ƶ��
    result.clear();     // �ܹؼ���һ������Ҫ�������result��֮ǰresult���Ԫ�ض�ʧЧ��
    result.push_back(cur->val);
}
~~~
�����������£���ֻ��Ҫ����һ�������������������������ļ��ϣ�
~~~c
class Solution {
private:
    int maxCount = 0; // ���Ƶ��
    int count = 0; // ͳ��Ƶ��
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return ;

        searchBST(cur->left);       // ��
                                    // ��
        if (pre == NULL) { // ��һ���ڵ�
            count = 1;
        } else if (pre->val == cur->val) { // ��ǰһ���ڵ���ֵ��ͬ
            count++;
        } else { // ��ǰһ���ڵ���ֵ��ͬ
            count = 1;
        }
        pre = cur; // ������һ���ڵ�

        if (count == maxCount) { // ��������ֵ��ͬ���Ž�result��
            result.push_back(cur->val);
        }

        if (count > maxCount) { // ��������������ֵƵ��
            maxCount = count;   // �������Ƶ��
            result.clear();     // �ܹؼ���һ������Ҫ�������result��֮ǰresult���Ԫ�ض�ʧЧ��
            result.push_back(cur->val);
        }

        searchBST(cur->right);      // ��
        return ;
    }

public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = NULL; // ��¼ǰһ���ڵ�
        result.clear();

        searchBST(root);
        return result;
    }
};
~~~