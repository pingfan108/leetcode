/*
# 118. 杨辉三角
https://leetcode-cn.com/problems/pascals-triangle/

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

    示例:
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

// 解法1:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;
        if (numRows < 1) {
            return res;
        }
        for (int row = 1; row <= numRows; row++) {
            std::vector<int> tmp(row, 1);
            if (row > 2) {
                std::vector<int> prev = res[row-2];
                for (int i = 1; i < prev.size(); i++) {
                    tmp[i] = prev[i] + prev[i-1];
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
