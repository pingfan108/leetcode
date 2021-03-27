/*
# 485. 最大连续 1 的个数
https://leetcode-cn.com/problems/max-consecutive-ones/

给定一个二进制数组， 计算其中最大连续 1 的个数。

    示例1：
输入：[1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
    示例2：
输入：[1]
输出：1

    提示：
输入的数组只包含 0 和 1 。
输入数组的长度是正整数，且不超过 10,000。
 */

// 解法1: 快慢指针
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int fast = 0, slow = -1;
        int maxLen = 0;
        while (fast < nums.size()) {
            if (nums[fast] == 0) {
                maxLen = std::max(maxLen, fast - slow - 1);
                slow = fast;
            }
            fast++;
        }
        return std::max(maxLen, fast - slow - 1);
    }
};
