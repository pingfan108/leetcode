/*
# 501. 二叉搜索树中的众数
https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
假定 BST 有如下定义：
    * 结点左子树中所含结点的值小于等于当前结点的值
    * 结点右子树中所含结点的值大于等于当前结点的值
    * 左子树和右子树都是二叉搜索树

    例如：
给定 BST [1,null,2,2],
   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序
进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 */

#include "include/tree.h"

// 解法1: 中序遍历 + 状态更新
// 思路:
// * 一棵BST的中序遍历的结果应该是一个单调不减(可能有重复元素)的数组, 在BST中有
//   相同值的两个节点一定是其中序遍历结果中的相邻节点;
// * 对输入BST做中序遍历, 遍历过程中记录prev节点, 当前节点val的频率计数以及历史
//   已出现的最大频率, 将出现频率最大的取值记录即可.
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        prev = NULL;
        maxCount = 0;

        vector<int> res;
        inOrder(root, res);
        return res;
    }

    void inOrder(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;

        // 递归处理左子树
        inOrder(root->left, res);

        // 处理当前节点
        do {
            if (prev != NULL && root->val == prev->val) {
                count++;    // 重复出现的取值
            } else {
                count = 1;  // 首次出现的取值
            }

            if (count < maxCount) {
                // 出现频率还不高, 无需记录
                break;
            } else if (count > maxCount) {
                // 当前取值的出现频次超出历史最大频次, 需清空原有记录
                res.clear();
                maxCount = count;
            }
            // 记录当前出现频率最高的取值
            res.push_back(root->val);
        } while (0);
        // 当前节点处理结束, prev指针移到当前节点
        prev = root;

        // 递归处理右子树
        inOrder(root->right, res);
    }

private:
    TreeNode* prev;
    int count;
    int maxCount;
};
