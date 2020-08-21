/*
# 111. 二叉树的最小深度
https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。

    示例:
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
 */
#include "include/tree.h"

// 解法1: 递归求解
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;  // 空二叉树
        } else if (root->left == NULL && root->right == NULL) {
            return 1;  // 找到叶子节点
        }

        int lDepth = minDepth(root->left);   // 递归求左子树的最小深度
        int rDepth = minDepth(root->right);  // 递归求右子树的最小深度
        if (root->left == NULL) {
            return rDepth + 1;
        } else if (root->right == NULL) {
            return lDepth + 1;
        }
        return std::min(lDepth, rDepth) + 1;
    }
};
