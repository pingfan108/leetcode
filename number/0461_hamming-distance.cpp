/*
# 461. 汉明距离
https://leetcode-cn.com/problems/hamming-distance/

两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。
    注意：
0 ≤ x, y < 2^31.

    示例:
输入: x = 1, y = 4
输出: 2
解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
 */

// 解法1: 位运算 + Brian Kernigham算法
// 思路:
// * 汉明距离 == 两数对应二进制位不同的位置数 == 两数按位异或的结果中1的个数;
// * Brian Kernigham算法可以快速清除一个二进制数最右边的1, 循环调用该算法将一个
//   数清除到0, 统计在此过程中调用该算法的次数即可得知该二进制数中1的个数.
class Solution {
public:
    int hammingDistance(int x, int y) {
        // Step1: 求出两个数 按位异或 的结果, 记为tmp
        int tmp = x ^ y;
        // Step2: 用Brian Kernigham算法将tmp清除到0
        int cnt = 0;
        while (tmp > 0) {
            tmp = tmp & (tmp - 1);  // 清除tmp的二进制串最右边的1
            cnt++;                  // 统计调用次数
        }
        // Step3: Brian Kernigham算法的调用次数, 即为两原始输入数的汉明距离
        return cnt;
    }
};
