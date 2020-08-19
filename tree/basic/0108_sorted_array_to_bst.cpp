/*
# 108. 将有序数组转换为二叉搜索树
https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

	示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5
 */
#include "include/tree.h"

// 解法1: 递归求解
// 思路:
// * 找到数组中点, 以此作为BST根节点; 将数组二分: [0,mid-1], [mid+1,len-1]
// * 递归地 将前半段数组,后半段数组 分别转为 根节点的左子树,右子树即可
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int low, int high) {
        // 特殊case: 处理空数组的场景
        if (low > high) {
            return NULL;
        }

        // 以数组中间元素mid为所求BST的root节点
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // 以mid将数组切成两段, 递归地将两段分别转成root的左右子树
        root->left = sortedArrayToBSTCore(nums, low, mid - 1);
        root->right = sortedArrayToBSTCore(nums, mid + 1, high);
        // 返回root节点即可
        return root;
    }
};
