/*
# 1004. 最大连续1的个数 III
https://leetcode-cn.com/problems/max-consecutive-ones-iii/

给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
返回仅包含 1 的最长（连续）子数组的长度。

    示例 1：
输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：
[1,1,1,0,0,01,1,1,1,1,01]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
    示例 2：
输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,01,01,1,1,1,01,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。

    提示：
1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 
 */

// 解法1: 滑动窗口(快慢指针)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // 用作滑动窗口左右边界的快慢指针
        int fast = 0, slow = 0;
        // 记录窗口滑动过程中的最大长度
        int maxLen = 0;
        // 记录滑动窗口当前范围内0的个数
        int cnt0 = 0;
        // 外循环完成快指针(窗口右边界)的滑动
        while (fast < A.size()) {
            if (A[fast++] == 0) {
                cnt0++;
                // 内循环完成慢指针(窗口左边界)的滑动
                while (cnt0 > K && slow < fast) {
                    if (A[slow++] == 0) {
                        cnt0--;
                    }
                }
            }
            // 尝试用当前(符合条件的)窗口的长度更新结果
            maxLen = std::max(maxLen, fast - slow);
        }
        return maxLen;
    }
};
