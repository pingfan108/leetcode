/*
# 832. 翻转图像
https://leetcode-cn.com/problems/flipping-an-image/

给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。

    示例 1:
输入: [[1,1,0],[1,0,1],[0,0,0]]
输出: [[1,0,0],[0,1,0],[1,1,1]]
解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
    示例 2:
输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

    说明:
1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
 */

// 解法1: 左右指针遍历
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++) {
            int j = 0, k = n-1;
            for (; j < k; j++,k--) {
                // 对于 A[i][j] 和 A[i][k], 可能有四种情形:
                //   (0,0) ==水平翻转==> (0,0) ==反转==> (1,1)
                //   (0,1) ==水平翻转==> (1,0) ==反转==> (0,1)
                //   (1,0) ==水平翻转==> (0,1) ==反转==> (1,0)
                //   (1,1) ==水平翻转==> (1,1) ==反转==> (0,0)
                // 归纳一下, 就是: 两数相等则取反, 两数相异则不变
                if (A[i][j] == A[i][k]) {
                    A[i][j] ^= 1;
                    A[i][k] ^= 1;
                }
            }
            // 特殊case: n为奇数时, 中轴线上的元素需要反转
            if (j == k) {
                A[i][j] ^= 1;
            }
        }
        return A;
    }
};
