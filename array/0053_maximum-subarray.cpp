/*
# 53. 最大子序和
https://leetcode-cn.com/problems/maximum-subarray/

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 

    示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
    示例 2：
输入：nums = [1]
输出：1
    示例 3：
输入：nums = [0]
输出：0
    示例 4：
输入：nums = [-1]
输出：-1
    示例 5：
输入：nums = [-100000]
输出：-100000

    提示：
1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 */

// 解法1: 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;  // 记录最终结果
        int sum = 0;        // 记录当前元素 之前的&&相邻的 最大子序和
        for (int i = 0; i < nums.size(); i++) {
            // 将当前元素加入之前的 连续子数组, 计算增长后的子数组
            sum += nums[i];
            // 尝试用当前的sum更新最终结果
            res = std::max(res, sum);
            // 截止到当前元素, 目前的连续子数组总和为负, 对于后续的子数组
            // 没有增益, 可以舍弃, 让后面的子数组从头开始
            sum = std::max(sum, 0);
        }
        return res;
    }
};
