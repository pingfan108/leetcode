/*
# 101. 对称二叉树
https://leetcode-cn.com/problems/symmetric-tree/

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3

	进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
 */
#include "include/tree.h"

// 解法1: 递归判断
// 思路:
// * 用两个指针同时指向这棵二叉树的根节点, 沿相反方向, 成镜像对称方式同步遍历
//   左右子树, 检查每一个节点的对称性.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 将输入的根结点复制, 使问题归一
        return isSymmetricCore(root, root);
    }

    bool isSymmetricCore(TreeNode *t1, TreeNode *t2) {
        // 两边皆空, 对称
        if (t1 == NULL && t2 == NULL) return true;
        // 单边为空, 非对称
        if (t1 == NULL || t2 == NULL) return false;
        // 两边非空, 对称 <==> 当前节点值相等, 左右子树分别对称
        return (t1->val == t2->val)
                && isSymmetricCore(t1->left, t2->right)
                && isSymmetricCore(t1->right, t2->left);
    }
};
