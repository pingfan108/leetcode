/*
# 129. 求根到叶子节点数字之和
https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。

    示例 1:
输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.

    示例 2:
输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
 */

#include "include/tree.h"

// 解法1: 带状态的前序遍历
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        total = 0;
        sumNumbersCore(root, 0);
        return total;
    }

    // 基于递归的二叉树前序遍历
    void sumNumbersCore(TreeNode* curr, int sum) {
        // 递归终止
        if (curr == NULL) {
            return;
        }

        // 处理当前节点
        sum = sum * 10 + curr->val;
        if (curr->left == NULL && curr->right == NULL) {
            total += sum;
        }
        // 递归处理当前节点的左右子树
        sumNumbersCore(curr->left, sum);
        sumNumbersCore(curr->right, sum);
    }

private:
    int total;
};
