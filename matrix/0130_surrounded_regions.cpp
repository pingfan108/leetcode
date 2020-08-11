/*
130. 被围绕的区域

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

    示例:
X X X X
X O O X
X X O X
X O X X
    运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
    解释:
被围绕的区间不会存在于边界上，
换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 */

// 解法1: DFS
// 思路: 先通过DFS找到所有与边界上的'O'相连的'O', 标记为特殊字符'#'; 然后遍历
//       整个矩阵, 将所有没有被标记的'O'改成'X', 同时将标记元素改回'O'即可.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //// 特殊case: 只有边界元素, 不用处理的情况
        if (board.size() < 3 || board[0].size() < 3) {
            return;  // 行列不足三, 元素皆在边
        }

        //// 一般case: DFS
        // Step1: 处理每一行的左右边界元素, 标记所有与边界相连的'O'
        for (int i = 0; i < board.size(); i++) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }
        // Step2: 处理每一列的上下边界元素, 标记所有与边界相连的'O'
        for (int j = 1; j < board[0].size() - 1; j++) {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }
        // Step3: 遍历矩阵所有元素, 将未被标记的'O'(也就是被'X'包围的'O')转为'X'
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }

    // 深度优先遍历
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() ||         // 横坐标超出范围
                j < 0 || j >= board[0].size() ||  // 纵坐标超出范围
                board[i][j] != 'O') {             // '#'(已经遍历过的'O')或'X'
            return;
        }
        // 标记已经遍历过的'O'
        board[i][j] = '#';
        // 继续遍历相邻元素
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
};
