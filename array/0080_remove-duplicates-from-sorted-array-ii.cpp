/*
# 80. 删除排序数组中的重复项 II
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
    注意:
* 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
* 你不需要考虑数组中超出新长度后面的元素。

    示例 1:
给定 nums = [1,1,1,2,2,3],
函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
    示例 2:
给定 nums = [0,0,1,1,1,1,2,3,3],
函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
 */

// 解法1: 快慢指针法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 特殊case: 不需要移除重复项的情况
        if (nums.size() < 3) {
            return nums.size();
        }
        // 一般case: 用快慢指针一轮遍历
        int slow = 0, fast = 1;
        int dup = 0;  // 记录当前元素重复出现的次数
        while (fast < nums.size()) {
            if (nums[fast] == nums[slow]) {
                if (++dup > 1) {
                    // 跳过重复出现两次以上的元素
                    fast++;
                    continue;
                }
            } else {
                dup = 0;  // slow指针移向不重复的新元素, 重复次数清零
            }
            nums[++slow] = nums[fast++];
        }
        return slow+1;
    }
};
