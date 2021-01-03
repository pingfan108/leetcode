/*
# 222. 完全二叉树的节点个数
https://leetcode-cn.com/problems/count-complete-tree-nodes/

给出一个完全二叉树，求出该树的节点个数。
完全二叉树的定义如下：
  * 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值
  * 并且最下面一层的节点都集中在该层最左边的若干位置。
  * 若最底层为第 h 层，则该层包含 1~ 2h 个节点。

    示例:
输入:
    1
   / \
  2   3
 / \  /
4  5 6
输出: 6
 */

// 解法1: 普通二叉树的遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 解法2: 完全二叉树的性质
// 思路:
// * 如果根节点的左子树深度等于右子树深度，则说明左子树为满二叉树
// * 如果根节点的左子树深度大于右子树深度，则说明右子树为满二叉树
// * 满二叉树的节点数目：(1<<depth) - 1, 其中depth为子树的深度
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        TreeNode* next;  // 需要继续递归处理的子树(左右)
        int depth;       // 另一棵子树的高度
        // 获取左右子树的高度
        int ldepth = getDepth(root->left);
        int rdepth = getDepth(root->right);
        if (ldepth == rdepth) {
            // 左右等高, 左子树是满二叉树
            depth = ldepth;      // 记录左子树的高度
            next = root->right;  // 右子树的节点数需要继续递归
        } else {
            // 左高右低, 右子树是满二叉树
            depth = rdepth;      // 记录右子树的高度
            next = root->left;   // 左子树的节点数需要继续递归
        }
        int count = 1 << depth;  // 满二叉子树 + 当前root
        return count + countNodes(next);
    }

    // 求完全二叉树的深度
    int getDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        // 普通二叉树需要求左右子树的较大值; 但对于完全二叉树, 只需看左子树
        return 1 + getDepth(root->left);
    }
};
