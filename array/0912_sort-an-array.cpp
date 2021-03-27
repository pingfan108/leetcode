/*
# 912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。

    示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]
    示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

    提示：
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
 */

// 解法1: 快速排序
// 思路: 基于挖坑法分区, 对两个分区递归求解
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortInternal(nums, 0, nums.size()-1);
        return nums;
    }

    void sortInternal(std::vector<int>& nums, int l, int r) {
        // 递归终止条件
        if (l >= r) {
            return;
        }

        int i = l, j = r;
        int k = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= k) {
                j--;
            }
            if (i < j) {
                nums[i] = nums[j];
            }

            while (i < j && nums[i] < k) {
                i++;
            }
            if (i < j) {
                nums[j] = nums[i];
            }
        }
        nums[i] = k;
        sortInternal(nums, l, i-1);
        sortInternal(nums, i+1, r);
    }
};
