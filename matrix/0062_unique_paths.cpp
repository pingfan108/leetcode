/*
# 62. 不同路径
https://leetcode-cn.com/problems/unique-paths/

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？

	示例 1:
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

	示例 2:
输入: m = 7, n = 3
输出: 28

	提示：
1 <= m, n <= 100
题目数据保证答案小于等于 2 * 10 ^ 9
 */

// 解法1: 动态规划(使用状态矩阵)
class Solution {
public:
    int uniquePaths(int m, int n) {
        //// Step1: 定义并初始化状态矩阵
        // dp[i][j]表示机器人到达(i,j)的可能路径数
        std::vector<std::vector<int> > dp(m, std::vector<int>(n, 0));
        dp[0][0] = 1;
        // 上边界的特殊处理, 只能按照从左往右移动的唯一路径, 路径数为一
        for (int i = 1; i < m; i++) dp[i][0] = 1;
        // 左边界的特殊处理, 只能按照从上往下移动的唯一路径, 路径数为一
        for (int j = 1; j < n; j++) dp[0][j] = 1;

        //// Step2: 遍历填充矩阵
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
