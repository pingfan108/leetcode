/*
# 1030. 距离顺序排列矩阵单元格
https://leetcode-cn.com/problems/matrix-cells-in-distance-order/

给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。
另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。
返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，
其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。（你可以按任何满足此条件的顺序返回答案。）

    示例 1：
输入：R = 1, C = 2, r0 = 0, c0 = 0
输出：[[0,0],[0,1]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1]
    示例 2：
输入：R = 2, C = 2, r0 = 0, c0 = 1
输出：[[0,1],[0,0],[1,1],[1,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
    示例 3：
输入：R = 2, C = 3, r0 = 1, c0 = 2
输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。

    提示：
1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C
 */

// 解法1: 桶排序
class Solution {
public:
    // 求曼哈顿距离
    int getDist(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // 创建桶排序的桶[0, MAX]
        int maxDist = max(r0, R-1-r0) + max(c0, C-1-c0);
        vector<vector<vector<int>>> buckets(maxDist+1);

        // 遍历取值范围内的所有坐标, 按照曼哈顿距离丢到具体的桶里面
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dist = getDist(r0, c0, i, j);
                vector<int> point = {i,j};
                buckets[dist].push_back(std::move(point));
            }
        }

        // 从小到大遍历所有的桶, 填充结果数组
        vector<vector<int>> res;
        for (int i = 0; i <= maxDist; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                res.push_back(buckets[i][j]);
            }
        }
        return res;
    }
};

// 解法2: 直接排序
// 解法3: 几何遍历
