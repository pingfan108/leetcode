/*
# 1365. 有多少小于当前数字的数字
https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
以数组形式返回答案。
    提示：
2 <= nums.length <= 500
0 <= nums[i] <= 100

    示例 1：
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释：
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。
对于 nums[3]=2 存在一个比它小的数字：（1）。
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
    示例 2：
输入：nums = [6,5,4,8]
输出：[2,1,0,3]
    示例 3：
输入：nums = [7,7,7,7]
输出：[0,0,0,0]
 */

// 解法1: 计数排序 + 前缀和
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 统计nums中每个数字出现的次数
        std::vector<int> count(101, 0);  // 0 <= nums[i] <= 100
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        // 将count转化为前缀和
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i-1];
        }

        // 再次遍历nums, 根据count可以查询到比当前元素小的元素计数
        std:vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                res.push_back(0);  // 根据题意, 没有比0小的数
            } else {
                res.push_back(count[nums[i] - 1]);
            }
        }
        return res;
    }
};

// 解法2: 快速排序
