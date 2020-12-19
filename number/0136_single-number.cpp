/*
# 136. 只出现一次的数字
https://leetcode-cn.com/problems/single-number/

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

    示例 1:
输入: [2,2,1]
输出: 1
    示例 2:
输入: [4,1,2,1,2]
输出: 4
 */

// 解法1: 位运算
// 思路:
// * 依次对所有的元素做异或运算, 因为相同元素的异或结果为0, 所以异或最终的结果
//   就是那个只出现了一次的元素.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int &n : nums) {
            res ^= n;  // 出现两次的元素会被异或运算消掉
        }
        return res;
    }
};
