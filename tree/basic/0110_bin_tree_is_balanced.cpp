/*
# 110. 平衡二叉树
https://leetcode-cn.com/problems/balanced-binary-tree/

给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

	示例 1:
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。

	示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
 */
#include "tree.h"

// 解法1: 递归遍历求解
// 思路:
// * 基于后序遍历递归获取每个节点的左右子树树高, 比较树高差是否超过1
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }

    // 基于后序遍历, 在获取二叉树深度的同时检查其平衡性
    // 如果当前子树平衡, 返回当前子树的高度; 反之, 返回-1
    int getHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        // 递归获取当前子树左子树的高度
        int lHeight = getHeight(root->left);
        if (lHeight < 0) {
            return -1;  // 当前子树的左子树不平衡
        }
        // 递归获取当前子树右子树的高度
        int rHeight = getHeight(root->right);
        if (rHeight < 0) {
            return -1;  // 当前子树的右子树不平衡
        }
        // 检查当前子树的左右子树高度差
        if (abs(lHeight - rHeight) > 1) {
            return -1;  // 当前子树不平衡
        }
        // 返回当前子树的高度
        return std::max(lHeight, rHeight) + 1;
    }
};
