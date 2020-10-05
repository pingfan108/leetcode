/*
# 1. 两数之和
https://leetcode-cn.com/problems/two-sum/

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

    示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */

// 解法1: 暴力双重循环
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

// 解法2: 基于哈希表记忆的一次遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        // 用一个哈希表遍历过程中已出现的数和它对应的索引
        std::unordered_map<int, int> num2Idx;
        // 遍历nums数组
        for (int i = 0; i < nums.size(); i++) {
            // 检索之前已遍历的元素是否能和当前元素组队
            auto it = num2Idx.find(target - nums[i]);
            // 已找到符合条件的两个数, 记录其索引, 直接退出遍历
            if (it != num2Idx.end()) {
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            // 不符合条件, 将当前元素记录到哈希表, 继续遍历下一个元素
            num2Idx[nums[i]] = i;
        }
        return res;
    }
};

// 解法3: 排序 + 左右指针
// 备注: 如果题目允许返回数据中具体的元素, 而不是返回数组下标, 可以先排序再用
//       左右指针逼近, 参照"15.三数之和", "18.四数之和"
