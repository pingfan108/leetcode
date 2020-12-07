/*
# 861. 翻转矩阵后的得分
https://leetcode-cn.com/problems/score-after-flipping-matrix/

有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
返回尽可能高的分数。

    示例：
输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    提示：
1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1
 */

// 解法1: 贪心
// 思路:
// * 以列为基准, 分开计算每一列可能得到的最大和
// * 总体最大必然要求首列皆为1; 而对于首列, 因为第一个处理, 一定有方法全转为1;
// * 对于后续列, 统计每一列中1的个数, 若1的个数少于0的个数, 此列翻转后再计算;
//   当然, 统计的时候需要检查每一行的首列元素, 如果是0, 需要先翻转再统计
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        // 计算首列的最大和(全为1)
        int sum = m * (1 << (n-1));
        // 遍历次列到尾列, 计算每一列的最大和
        for (int j = 1; j < n; j++) {
            // 遍历当前列, 统计当前1的个数
            int count1 = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][0] == 1) {
                    // 当前行首列为1, 则此行无需翻转, 使用原始值
                    count1 += A[i][j];
                } else {
                    // 当前行首列为0, 则此行需要翻转, 使用翻转值
                    count1 += (1 - A[i][j]);
                }
            }
            // 如果1的个数少于0的个数, 此列需翻转
            count1 = std::max(count1, m - count1);
            // 依照最终1的个数, 计算此列的最大和, 累加到结果
            sum += count1 * (1 << (n-1-j));
        }
        return sum;
    }
};