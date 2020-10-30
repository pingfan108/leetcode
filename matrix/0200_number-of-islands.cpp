/*
# 200. 岛屿数量
https://leetcode-cn.com/problems/number-of-islands/

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

    示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
    示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3

    提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
 */

// 解法1: 深度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                count += dfs(grid, i, j);
            }
        }
        return count;
    }

    // 基于深度优先策略搜索当前岛屿(i,j分别表示行号和列号)
    int dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size()            // 超出上下边界
                || j < 0 || j >= grid[0].size()  // 超出左右边界
                || grid[i][j] != '1') {          // "水域"或已访问的"陆地"
            return 0;
        }

        // 找到一块新"陆地", 标记已访问
        grid[i][j] = '2';
        // 继续搜索四周, 找到所有相邻"陆地", 搭上标记
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        // 已搜索完毕一个岛屿
        return 1;
    }
};
