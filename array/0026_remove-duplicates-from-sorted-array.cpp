/*
# 26. 删除排序数组中的重复项
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    注意
* 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
* 你不需要考虑数组中超出新长度后面的元素。

    示例 1:
给定数组 nums = [1,1,2],
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

    示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 */

// 解法1: 快慢指针法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 特殊case: 肯定没有重复项的情况
        if (nums.size() < 2) {
            return nums.size();
        }
        // 一般case: 用快慢指针一轮遍历
        int slow = 0, fast = 1;
        while (fast < nums.size()) {
            if (nums[fast] == nums[slow]) {
                //  跳过重复出现的元素
                fast++;
                continue;
            }
            nums[++slow] = nums[fast++];
        }
        return slow+1;
    }
};
