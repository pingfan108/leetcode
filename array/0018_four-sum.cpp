/*
# 18. 四数之和
https://leetcode-cn.com/problems/4sum/

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
找出所有满足条件且不重复的四元组。
    注意：
答案中不可以包含重复的四元组。

    示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */

// 解法1: 排序 + 三重循环 + 左右指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int> > res;
        /* 排除肯定无解的情况 */
        if (nums.size() < 4) return res;

        /* 将nums数组排序(方便去重, 也是使用左右指针的必要条件) */
        std::sort(nums.begin(), nums.end());

        /* 三重循环 + 左右指针逼近 */
        // 第一重循环, 枚举所有可能的nums[i]
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i && nums[i] == nums[i-1]) {
                continue;  // 排除重复的四元组
            }
            // 第二重循环, 枚举所有可能的nums[j]
            for (int j = i+1; j < nums.size() - 2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;  // 排除重复的四元组
                }
                // 第三重循环, 采用左右指针夹逼找到所有可能的nums[x],nums[y]
                int x = j+1, y = nums.size() - 1;
                while (x < y) {
                    int sum = nums[i] + nums[j] + nums[x] + nums[y];
                    if (sum < target) {
                        x++;  // 和太小, 左指针后移枚举更大的nums[x]
                    } else if (sum > target) {
                        y--;  // 和太大, 右指针后移枚举更小的nums[y]
                    } else {
                        // 找到符合条件(sum == target)的四元组
                        res.push_back({nums[i], nums[j], nums[x], nums[y]});
                        // 排除重复的四元组
                        while (x < y && nums[x] == nums[++x]);
                        while (x < y && nums[y] == nums[--y]);
                    }
                }
            }
        }
        return res;
    }
};
