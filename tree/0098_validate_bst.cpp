/*
# 98. 验证二叉搜索树
https://leetcode-cn.com/problems/validate-binary-search-tree/

给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
* 节点的左子树只包含小于当前节点的数。
* 节点的右子树只包含大于当前节点的数。
* 所有左子树和右子树自身必须也是二叉搜索树。

    示例 1:
输入:
    2
   / \
  1   3
输出: true

    示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
 */
#include "include/tree.h"

// 解法1: 中序遍历 + prev指针
// 思路:
// * 一棵BST的中序遍历的结果应该是一个单调递增且无重复元素(题目描述保证)的数组;
// * 对输入二叉树做中序遍历, 遍历过程中用一个额外的指针记录前一个节点取值, 比较
//   当前节点和前一节点的取值是否打破升序规则即可验证这是否为一棵二叉树.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        // 使用long类型, 是因为有一个测试case用了INT_MIN作为根节点的val
        long prev = LONG_MIN;
        return isValidBSTCore(root, &prev);
    }

    // 基于中序遍历递归地检查当前子树是否是一个合法的BST
    bool isValidBSTCore(TreeNode* curr, long *prev) {
        if (curr == NULL) {
            return true;
        }

        if (!isValidBSTCore(curr->left, prev) ||   // 递归检查左子树是否为BST
                curr->val <= *prev) {   // 检查当前节点是否满足升序排列规则
            return false;
        }
        *prev = curr->val;              // 更新prev
        return isValidBSTCore(curr->right, prev);  // 递归检查右子树是否为BST
    }
};

// 解法2: 前序遍历 + 上下限
// 思路:
// * 一棵BST的左子树中只包含小于当前节点的数, 每一次往下遍历其取值上限在降低;
// * 一棵BST的右子树中只包含大于当前节点的数, 每一次往下遍历其取值下限在提升;
// * 遍历过程中按照此规则更新上限/下限, 检查子树节点的取值是否上下限范围内即可.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        // 使用long类型, 是因为有一个测试case用了INT_MIN作为根节点的val
        long lower = LONG_MIN;
        long upper = LONG_MAX;
        return isValidBSTCore(root, lower, upper);
    }

    // 基于前序遍历递归地检查当前子树是否是一个合法的BST
    bool isValidBSTCore(TreeNode* curr, long lower, long upper) {
        if (curr == NULL) {
            return true;
        }

        // 检查当前节点的取值是否在上下限范围内
        if (curr->val <= lower || curr->val >= upper) {
            return false;
        }
        // 递归检查当前节点的左子树和右子树是否为BST
        // 对于curr->left, 所有节点的取值只能小于当前节点, 更新上限为curr->val;
        // 对于curr->right, 所有节点的取值只能大于当前节点, 更新下限为curr->val;
        return isValidBSTCore(curr->left, lower, curr->val) &&
                isValidBSTCore(curr->right, curr->val, upper);
    }
};
