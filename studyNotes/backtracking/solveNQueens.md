# [N�ʺ�](https://leetcode.cn/problems/n-queens/)
���չ�������Ĺ��򣬻ʺ���Թ�����֮����ͬһ�л�ͬһ�л�ͬһб���ϵ����ӡ�

n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������

����һ������ n ���������в�ͬ�� n �ʺ����� �Ľ��������

ÿһ�ֽⷨ����һ����ͬ�� n �ʺ����� �����ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��

## ʾ�� 1��
![](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)  
���룺n = 4  
�����[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]  
���ͣ�����ͼ��ʾ��4 �ʺ��������������ͬ�Ľⷨ��  

## ˼·  
��֪��n�ʺ������ǻ����㷨����ľ������⣬�����û��ݽ��������ϡ��и�Ӽ�����������֮���������ֶ�ά���󻹻��е㲻֪���롣  

��������һ�»ʺ��ǵ�Լ��������  

����ͬ��  
����ͬ��  
����ͬб��  
ȷ����Լ������������������Ҫ��ôȥ�����ʺ��ǵ�λ�ã���ʵ�����ʺ��λ�ã����Գ���Ϊһ����  

��ô�����ûʺ��ǵ�Լ�������������������������ֻҪ������������Ҷ�ӽڵ㣬˵�����ҵ��˻ʺ��ǵĺ���λ���ˡ�

### ����������
�������ܽ�����»���ģ�壬���������η�����
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
�ݹ麯������
����Ȼ�Ƕ���ȫ�ֱ�����ά����result����¼���ս����

����n�����̵Ĵ�С��Ȼ����row����¼��ǰ���������̵ĵڼ����ˡ�

�������£�
~~~c
vector<vector<string>> result;
void backtracking(int n, int row, vector<string>& chessboard) {
�ݹ���ֹ����
~~~

�������£�
~~~c
if (row == n) {
    result.push_back(chessboard);
    return;
}
~~~
�����������߼�
�ݹ���Ⱦ���row�������̵��У�ÿһ����forѭ����col�������̵��У�һ��һ�У�ȷ���˷��ûʺ��λ�á�

ÿ�ζ���Ҫ���µ�һ�е���ʼλ�ÿ�ʼ�ѣ����Զ��Ǵ�0��ʼ��

�������£�
~~~c
for (int col = 0; col < n; col++) {
    if (isValid(row, col, chessboard, n)) { // ��֤�Ϸ��Ϳ��Է�
        chessboard[row][col] = 'Q'; // ���ûʺ�
        backtracking(n, row + 1, chessboard);
        chessboard[row][col] = '.'; // ���ݣ������ʺ�
    }
}
~~~
��֤�����Ƿ�Ϸ�
�������±�׼ȥ�أ�

����ͬ��
����ͬ��
����ͬб�� ��45�Ⱥ�135�Ƚǣ�
�������£�
~~~c
bool isValid(int row, int col, vector<string>& chessboard, int n) {
    // �����
    for (int i = 0; i < row; i++) { // ����һ����֦
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // ��� 45�Ƚ��Ƿ��лʺ�
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // ��� 135�Ƚ��Ƿ��лʺ�
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
~~~
����ݴ����У�ϸ�ĵ�ͬѧ���Է���Ϊʲôû����ͬ�н��м���أ�

��Ϊ�ڵ��������Ĺ����У�ÿһ��ݹ飬ֻ��ѡforѭ����Ҳ����ͬһ�У����һ��Ԫ�أ����Բ���ȥ���ˡ�

��ô�������ģ�岻��д������C++���룺
~~~c
class Solution {
private:
vector<vector<string>> result;
// n Ϊ��������̴�С
// row �ǵ�ǰ�ݹ鵽���̵ĵڼ�����
void backtracking(int n, int row, vector<string>& chessboard) {
    if (row == n) {
        result.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) { // ��֤�Ϸ��Ϳ��Է�
            chessboard[row][col] = 'Q'; // ���ûʺ�
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.'; // ���ݣ������ʺ�
        }
    }
}
bool isValid(int row, int col, vector<string>& chessboard, int n) {
    // �����
    for (int i = 0; i < row; i++) { // ����һ����֦
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // ��� 45�Ƚ��Ƿ��лʺ�
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // ��� 135�Ƚ��Ƿ��лʺ�
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};
~~~