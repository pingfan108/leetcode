/*
# 463. 岛屿的周长
https://leetcode-cn.com/problems/island-perimeter/

给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
网格中的格子水平和垂直方向相连（对角线方向不相连）。
整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

    示例 :
输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
输出: 16
 */

// 解法1: 深度优先搜索
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    // 题目限定只有一个岛屿, 从任意一块"陆地"开始一定能遍历整个
                    // 岛屿, 遍历结束得到即为整个岛屿的周长, 直接返回即可
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }

    // 基于深度优先策略搜索当前岛屿(i,j分别表示行号和列号)
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size()            // 走出上下边界
                || j < 0 || j >= grid[0].size()  // 走出左右边界
                || grid[i][j] == 0) {            // 走到水域
            return 1;  // 从"陆地"到"非陆地", 贡献一条边, 周长+1
        } else if (grid[i][j] == 2) {
            return 0;  // 重复访问的"陆地", 直接返回
        }

        // 这是一块新发现的"陆地", 标记已访问
        grid[i][j] = 2;
        // 计算当前"陆地"对周长的贡献值(看它四周是否到"非陆地")
        return dfs(grid, i-1, j)
                + dfs(grid, i+1, j)
                + dfs(grid, i, j-1)
                + dfs(grid, i, j+1);
    }
};
