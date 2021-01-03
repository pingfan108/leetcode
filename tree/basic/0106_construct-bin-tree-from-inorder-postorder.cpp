/*
# 106. 从中序与后序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

根据一棵树的中序遍历与后序遍历构造二叉树。
    注意:
你可以假设树中没有重复的元素。

    例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]

返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7

*/

#include "include/tree.h"

// 解法1: 递归求解(基于前序遍历框架)
// 思路:
// * 后序遍历序列的最后一个元素为二叉树root节点, 根据root节点可以将中序遍历序列
//   分为左右子序列;
// * 根据中序遍历左右子序列的长度, 反过来也可以将后续遍历序列切割为左右子序列;
// * 递归处理左右子序列可以构造出root节点的左右子树, 得解.
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeCore(inorder, 0, inorder.size()-1,
                postorder, 0, postorder.size()-1);
    }

    // 根据inorder和postorder的指定子序列构造子二叉树
    TreeNode* buildTreeCore(vector<int>& inorder, int ibeg, int iend,
            vector<int>& postorder, int pbeg, int pend) {
        // 子序列为空, 递归结束
        if (ibeg > iend) {
            return NULL;
        }

        // 以postorder子序列的最后一个元素作为当前子树的根节点
        auto root = new TreeNode(postorder[pend]);
        // 在inorder子序列中找到根节点的索引
        int i = ibeg;
        for (; i <= iend; i++) {
            if (inorder[i] == postorder[pend]) break;
        }
        // 计算当前子树的下一级左子树对应子序列的长度
        int llen = i - ibeg;

        // 递归构建当前子树的下一级左子树
        root->left = buildTreeCore(inorder, ibeg, i-1,
                postorder, pbeg, pbeg+llen-1);
        // 递归构建当前子树的下一级右子树
        root->right = buildTreeCore(inorder, i+1, iend,
                postorder, pbeg+llen, pend-1);
        return root;
    }
};
