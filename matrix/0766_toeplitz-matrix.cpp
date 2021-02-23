/*
# 766. 托普利茨矩阵
https://leetcode-cn.com/problems/toeplitz-matrix/

给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。
如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。

    示例 1：
输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
输出：true
解释：
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是 True 。
    示例 2：
输入：matrix = [[1,2],[2,2]]
输出：false
解释：
对角线 "[1, 2]" 上的元素不同。

    提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99

    进阶：
如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
 */

// 解法1: 定义法, 直接遍历每一条对角线
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() < 2 || matrix[0].size() < 2) {
            return true;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        // 遍历中心对角线以及其左下方的对角线
        for (int k = 0; k < m; k++) {
            for (int i = k+1, j = 1; i < m && j < n; i++, j++) {
                if (matrix[i][j] != matrix[k][0]) {
                    return false;
                }
            }
        }
        // 遍历中心对角线右上方的对角线
        for (int k = 1; k < n; k++) {
            for (int i = 1, j = k+1; i < m && j < n; i++, j++) {
                if (matrix[i][j] != matrix[0][k]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// 解法2: 进阶法, 遍历每个元素, 判断其与右下角的元素是否相等即可
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() < 2 || matrix[0].size() < 2) {
            return true;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
