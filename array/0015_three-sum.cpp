/*
# 15. 三数之和
https://leetcode-cn.com/problems/3sum/

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
请你找出所有满足条件且不重复的三元组。
    注意：
答案中不可以包含重复的三元组。

    示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

// 解法1: 排序 + 两重循环 + 左右指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int> > res;
        /* 排除肯定无解的情况 */
        if (nums.size() < 3) return res;

        /* 将nums数组排序(方便去重, 也是使用左右指针的必要条件) */
        std::sort(nums.begin(), nums.end());

        /* 两重循环 + 左右指针逼近 */
        // 第一重循环, 枚举所有可能的nums[i]
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                // 剪枝优化: 三数之和为0要求最小数为负数, 后面肯定找不到有效解
                break;
            }
            if (i && nums[i] == nums[i-1]) {
                // 排除重复的三元组
                continue;
            }

            // 第二重循环, 采用左右指针夹逼找到所有可能的nums[x],nums[y]
            int x = i+1, y = nums.size() - 1;
            while (x < y) {
                int sum = nums[i] + nums[x] + nums[y];
                if (sum < 0) {
                    x++;  // 和太小, 左指针后移枚举更大的nums[x]
                } else if (sum > 0) {
                    y--;  // 和太大, 右指针后移枚举更小的nums[y]
                } else {
                    // 找到符合条件(sum == target)的三元组
                    res.push_back({nums[i], nums[x], nums[y]});
                    // 排除重复的三元组
                    while (x < y && nums[x] == nums[++x]);
                    while (x < y && nums[y] == nums[--y]);
                }
            }
        }
        return res;
    }
};
