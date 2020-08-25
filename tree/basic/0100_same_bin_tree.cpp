/*
# 100. 相同的树
https://leetcode-cn.com/problems/same-tree/

给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

    示例 1:
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
输出: true

    示例 2:
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]
输出: false

    示例 3:
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
输出: false
 */
# include "include/tree.h"

// 解法1: 递归判断
// 思路:
// * 用两个指针分别指向两棵二叉树的根节点, 同步做前序遍历判断.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Step1: 两棵树都是空树 or 到达树枝末梢
        if (p == NULL && q == NULL) {
            return true;
        }

        // Step2: 检查当前遍历位置上节点是否取值有差异
        if (p == NULL || q == NULL || p->val != q->val) {
            return false;
        }
        // Step3: 递归检查当前遍历节点的左子树和右子树是否相同
        return isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
    }
};
