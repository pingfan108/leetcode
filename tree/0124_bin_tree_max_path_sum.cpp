/*
# 124. 二叉树中的最大路径和
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。
该路径至少包含一个节点，且不一定经过根节点。

	示例 1:
输入: [1,2,3]
       1
      / \
     2   3
输出: 6

	示例 2:
输入: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
输出: 42
 */
#include "include/tree.h"

// 解法1: 递归大法
// 思路:
// * 定义节点的最大贡献值: 以该节点为根节点的子树中寻找以其为起点的一条路径,
//   使得该路径上的节点值之和最大. 
//   * 空节点的最大贡献值等于 0;
//   * 叶节点的最大贡献值等于节点值本身;
//   * 非空节点的最大贡献值等于节点值与其子节点中的最大贡献值之和(递归).
// * 二叉树节点的最大路径和, 取决于该节点的值与其左右子节点的最大贡献值.
// * 对根节点调用最大贡献值函数，即可递归得到每个节点的最大贡献值; 在递归过程
//   中维护一个全局变量 maxSum 存储最大路径和, 递归结束可得结果.
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumCore(root, &res);
        return res;
    }

    // 递归函数, 计算当前节点的最大贡献值
    int maxPathSumCore(TreeNode *root, int *res) {
        if (root == NULL) {
            return 0;
        }

        // 求左子树的最大子路径和(若为负, 则舍弃)
        int lmax = std::max(maxPathSumCore(root->left, res), 0);
        // 求右子树的最大子路径和(若为负, 则舍弃)
        int rmax = std::max(maxPathSumCore(root->right, res), 0);

        // 更新最大路径和结果: 经过当前root节点的路径和 是否大于缓存的res
        *res = std::max(*res, root->val + lmax + rmax);
        // 返回 以当前节点作为部分路径的 情况下，此段子路径的最大值
        return root->val + std::max(lmax, rmax);
    }
};
