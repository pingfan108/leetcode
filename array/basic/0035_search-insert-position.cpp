/*
# 35. 搜索插入位置
https://leetcode-cn.com/problems/search-insert-position/

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

    示例 1:
输入: [1,3,5,6], 5
输出: 2
    示例 2:
输入: [1,3,5,6], 2
输出: 1
    示例 3:
输入: [1,3,5,6], 7
输出: 4
    示例 4:
输入: [1,3,5,6], 0
输出: 0
 */

// 解法1: 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 本质上是一个upper_bound的二分查找
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 特殊处理, 从逻辑上没必要, 只是为了加速返回
        if (nums.empty() || nums[0] >= target) return 0;
        if (nums[nums.size() - 1] < target) return nums.size();

        // 二分查找
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = l + (r - l)/2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
