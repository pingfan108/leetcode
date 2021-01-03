/*
# 217. 存在重复元素
https://leetcode-cn.com/problems/contains-duplicate/

给定一个整数数组，判断是否存在重复元素。
如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

    示例 1:
输入: [1,2,3,1]
输出: true
    示例 2:
输入: [1,2,3,4]
输出: false
    示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
 */

// 解法1: 哈希
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> dict;
        for (auto &num : nums) {
            auto it = dict.find(num);
            if (it != dict.end()) {
                return true;
            }
            dict.insert(num);
        }
        return false;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> dict(nums.begin(), nums.end());
        return nums.size() > dict.size();
    }
};
