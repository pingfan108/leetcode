/*
# 215. 数组中的第K个最大元素
https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

在未排序的数组中找到第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

    示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
    示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
    说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 */

// 解法0: 排序
// 思路: 非常直接, 先排序, 然后直接根据k算出索引N+1-k, 取相应位置的元素即可.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// 解法1: 借助快排的分区
// 思路:
// 1. 完整的做完排序代价太大了, 实际上如果是快排的话, partition的过程将数据分为
//    两边, 分界点就是第i大的元素;
// 2. 根据i和k的关系选定一个分区继续切分, 如此往复, 就可以找到第k大的切分点;
// 3. 一般排序默认是升序, 这样的话第k大就对应排序后的倒数第k个元素, 也就是正数
//    第k'(=N+1-k)个元素, 比较麻烦, 所以这里我们改为降序排列.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findInternal(nums, 0, nums.size()-1, k);
    }

    // 基于快排分区递归找第k个最大的元素
    int findInternal(vector<int>& nums, int l, int r, int k) {
        /* if (l > r) { return -1; } */
        // 基于挖坑法分区
        int i = l;
        int j = r;
        int p = nums[i];
        while (i < j) {
            while (i < j && nums[j] <= p) {
                j--;
            }
            if (i < j) {
                nums[i] = nums[j];
            }

            while (i < j && nums[i] > p) {
                i++;
            }
            if (i < j) {
                nums[j] = nums[i];
            }
        }
        nums[i] = p;
        // 根据分界点i和k-1的关系, 决定继续搜索那个集群区间
        if (i < k-1) {
            return findInternal(nums, i+1, r, k);
        } else if (i > k-1) {
            return findInternal(nums, l, i-1, k);
        }
        // i == k-1, 找到了第k个最大的元素
        return nums[i];
    }
};
