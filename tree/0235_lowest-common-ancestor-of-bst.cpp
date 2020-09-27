/*
# 235. 二叉搜索树的最近公共祖先
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

    示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
    示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

    说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
 */

#include "include/tree.h"

// 解法1: 后序遍历 + 二分查找
// 思路:
// * 对于两个待查找节点, 设取值较小节点的val为low, 另一节点的val为high;
// * 使用后序遍历搜索该二叉树, 基于BST的特性, 若当前节点的val比high还大, 说明
//   p和q均位于当前节点的左子树, 继续搜索当前节点的左子树即可;
// * 同理, 若当前节点的val比low还小, 说明p和q均位于当前节点的右子树, 继续搜索
//   当前节点的右子树即可;
// * 如果上述两个条件都不满足(等价于: 当前节点的val位于[low,high]的闭区间内),
//   则当前节点即为p和q的LCA
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 找出p和q两个节点取值的相对较小值low和较大值high
        int low = p->val < q->val ? p->val : q->val;
        int high = p->val + q->val - low;
        // 基于BST的特性, 二分搜索该二叉树
        return lcaBSTCore(root, low, high);
    }

    // 基于前序遍历的二分搜索
    // curr, 当前节点(当前子树的根节点)
    // low,  两个待查找节点取值的相对小值
    // high, 两个待查找节点取值的相对大值
    TreeNode* lcaBSTCore(TreeNode* curr, int low, int high) {
        // 递归终止条件
        if (curr == NULL) return NULL;

        // 根据当前节点与p,q取值的相对大小, 选择搜索一半的子树
        if (curr->val > high) {
            // p和q均位于当前节点的左子树
            return lcaBSTCore(curr->left, low, high);
        }
        if (curr->val < low) {
            // p和q均位于当前节点的右子树
            return lcaBSTCore(curr->right, low, high);
        }
        // p和q分别位于当前节点的左右 || 当前节点是p或q中的一个
        return curr;
    }
};
