/*
# 268. 丢失的数字
https://leetcode-cn.com/problems/missing-number/

给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
    进阶：
你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?

    示例 1：
输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
    示例 2：
输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
    示例 3：
输入：nums = [9,6,4,2,3,5,7,0,1]
输出：8
解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
    示例 4：
输入：nums = [0]
输出：1
解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。

    提示：
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
nums 中的所有数字都 独一无二
 */

// 解法1: 位运算
// 思路:
// * nums数组的下标i集合刚好是完整的[0,n-1], 相应的, i+1刚好是完整的[1,n]
// * 遍历nums数组, 依次对所有元素和其下标的i+1做做异或运算, 所有存在元素都会和
//   某一个i+1消掉, 最后剩下的就是丢失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
            res ^= (i + 1);
        }
        return res;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 初始为n, 和下标i的范围[0,n-1]组合起来, 就是完整的[0,n]
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};

// 解法2: 等差数列(高斯法)
// 思路:
// * 使用高斯公式可以直接得到[0,n]范围内所有数字的总和sum;
// * 遍历nums数组, 依次从sum中减去每个元素的值, 剩下的差就是丢失的数字.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // 高斯公式求和
        long sum = n * (n + 1) / 2;
        // 依次减去存在的元素
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        // 差即为丢失的数字
        return (int)sum;
    }
};
