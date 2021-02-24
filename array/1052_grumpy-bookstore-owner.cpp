/*
# 1052. 爱生气的书店老板
https://leetcode-cn.com/problems/grumpy-bookstore-owner/

今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。
在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。
书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。
请你返回这一天营业下来，最多有多少客户能够感到满意的数量。

    示例：
输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.

    提示：
1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
 */

// 解法1: 滑动窗口
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        // 用作滑动窗口左右边界的快慢指针
        int fast = 0, slow = 0;
        // 记录grumpy[i]为0时对应的顾客总数
        int sum0 = 0;
        // 记录窗口滑动过程中, 窗口内grumpy[i]为0的顾客数, 及其最大值
        int sum1 = 0, maxSum1 = 0;

        // 外循环完成快指针(窗口右边界)的滑动
        for (; fast < customers.size(); fast++) {
            if (grumpy[fast] == 1) {
                // 将右边界上被生气影响到的顾客数纳入当前窗口统计
                sum1 += customers[fast];
            } else {
                sum0 += customers[fast];
                continue;
            }
            // 内循环完成慢指针(窗口左边界)的滑动
            while (fast - slow >= X) {
                if (grumpy[slow] == 1) {
                    // 将左边界上被生气影响到的顾客数移出当前窗口统计
                    sum1 -= customers[slow];
                }
                slow++;
            }
            // 尝试用当前窗口内的sum1更新maxSum1
            maxSum1 = std::max(maxSum1, sum1);
        }
        return sum0 + maxSum1;
    }
};
