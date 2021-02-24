/*
# 1438. 绝对差不超过限制的最长连续子数组
https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
如果不存在满足条件的子数组，则返回 0 。

    示例 1：
输入：nums = [8,2,4,7], limit = 4
输出：2
解释：所有子数组如下：
[8] 最大绝对差 |8-8| = 0 <= 4.
[8,2] 最大绝对差 |8-2| = 6 > 4.
[8,2,4] 最大绝对差 |8-2| = 6 > 4.
[8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
[2] 最大绝对差 |2-2| = 0 <= 4.
[2,4] 最大绝对差 |2-4| = 2 <= 4.
[2,4,7] 最大绝对差 |2-7| = 5 > 4.
[4] 最大绝对差 |4-4| = 0 <= 4.
[4,7] 最大绝对差 |4-7| = 3 <= 4.
[7] 最大绝对差 |7-7| = 0 <= 4.
因此，满足题意的最长子数组的长度为 2 。
    示例 2：
输入：nums = [10,1,2,4,7,2], limit = 5
输出：4
解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
    示例 3：
输入：nums = [4,2,2,2,4,4,2,2], limit = 0
输出：3

    提示：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
 */

// 解法1: 滑动窗口(快慢指针)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.empty()) return 0;

        // 用作滑动窗口左右边界的快慢指针
        int fast = 0, slow = 0;
        // 记录窗口滑动过程中的最大长度
        int maxLen = 0;
        // 记录滑动窗口当前范围内的元素(并排序)
        std::multiset<int> numSet;
        // 外循环完成快指针(窗口右边界)的滑动
        while (fast < nums.size()) {
            // 将右边界的元素纳入窗口范围内, 
            numSet.insert(nums[fast]);
            // 移动快指针拓宽窗口右边界
            fast++;
            // 内循环完成慢指针(窗口左边界)的滑动
            while (slow < fast) {
                if (*numSet.rbegin() - *numSet.begin() <= limit) {
                    break;
                }
                // 将左边界元素移出窗口范围
                numSet.erase(numSet.find(nums[slow]));
                // 移动慢指针收窄窗口左边界
                slow++;
            }
            // 尝试用当前(符合条件的)窗口的长度更新结果
            maxLen = std::max(maxLen, fast - slow);
        }
        return maxLen;
    }
};
