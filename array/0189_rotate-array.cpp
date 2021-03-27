/*
# 189. 旋转数组
https://leetcode-cn.com/problems/rotate-array/

给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
    进阶：
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

    示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
    示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]

    提示：
1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 */

// 解法1: 语义操作
// 思路:
// * 复制一份原始序列, 分成[0,k-1], [k,n-1]两个子序列分别填充
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) {
            k %= n;
        }
        vector<int> tmp(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            nums[i] = tmp[n-k+i];
        }
        for (int i = k; i < n; i++) {
            nums[i] = tmp[i-k];
        }
    }
};
// 思路:
// * 复制一份原始序列, 基于取模关系逐个填充
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            nums[(i+k)%n] = tmp[i];
        }
    }
};

// 解法2: 两次翻转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 输入参数检查与处理
        int n = nums.size();
        if (n < 2) {
            return;
        } else if (k > n) {
            k %= n;  // k超过n的部分是重复循环, 没有意义
        }
        // 第一轮: 整个数组全部翻转
        reverse(nums, 0, n-1);
        // 第二轮: 分成两个子数组, 前k个元素&&后n-k个元素, 分别翻转
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    // 翻转输入数组的指定区间[l,r]
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
};
