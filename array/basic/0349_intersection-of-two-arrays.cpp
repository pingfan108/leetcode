/*
# 349. 两个数组的交集
https://leetcode-cn.com/problems/intersection-of-two-arrays/

给定两个数组，编写一个函数来计算它们的交集。

    示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
    示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]

    说明：
输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
 */

// 解法1: 哈希表
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;

        // 遍历nums1, 将nums1转存为集合
        std::unordered_set<int> nums;
        for (auto &num : nums1) {
            nums.insert(num);
        }

        // 遍历nums2, 如果nums2中的元素可以在集合中找到, 将其加入res
        for (auto &num : nums2) {
            if (nums.find(num) != nums.end()) {
                res.push_back(num);
                nums.erase(num);  // 避免输出结果中的元素重复
            }
        }
        return res;
    }
};

// 解法2: 排序+双指针
