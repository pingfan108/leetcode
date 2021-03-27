/*
# 283. 移动零
https://leetcode-cn.com/problems/move-zeroes/

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
    说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
 */

// 解法1: 顺序遍历
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0, i = 0;
        // 跳过开头的所有非0元素, 定位到第一个0(这一步只为加速, 省略不影响结果)
        while (i < nums.size() && nums[i]) {
            i++;
        }
        // 依次处理之后的每一个元素x, 非0则前移N位(N是x之前已经出现的0个数)
        for (;i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                nums[i-cnt] = nums[i];
            }
        }
        // 将数组尾部的N个元素置零(N是nums中0的总个数)
        i = nums.size() - cnt;
        while (cnt--) {
            nums[i+cnt] = 0;
        }
    }
};

// 解法2: 快慢指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        // 跳过开头的所有非0元素, 定位到第一个0(这一步只为加速, 省略不影响结果)
        while (fast < nums.size() && nums[fast]) {
            fast++;
            slow++;
        }
        while (fast < nums.size()) {
            if (nums[fast]) {
                std::swap(nums[fast], nums[slow]);
                slow++;
            }
            fast++;
        }
    }
};

// 解法3: 快排分区
