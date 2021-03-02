/*
# 867. 转置矩阵
https://leetcode-cn.com/problems/transpose-matrix/

给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。
矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

    示例 1：
输入：matrix = [[1,2,3],
                [4,5,6],
                [7,8,9]]
输出：[[1,4,7],
       [2,5,8],
       [3,6,9]]

    示例 2：
输入：matrix = [[1,2,3],
                [4,5,6]]
输出：[[1,4],
       [2,5],
       [3,6]]

    提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
 */

// 解法: 定义法
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return matrix;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        // 输入是m*n矩阵, 则输出是一个n*m矩阵
        vector<vector<int>> res(n, vector<int>(m, 0));
        // 依次遍历输入矩阵所有元素, 按照转置规则填充res矩阵
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
