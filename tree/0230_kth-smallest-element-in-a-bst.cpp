/*
# 230. 二叉搜索树中第K小的元素
https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
    说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

    示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1

    示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3

    进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
 */

// 解法1: 带状态的中序遍历
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        // 初始化计数器
        count = 0;
        // 中序遍历找kth节点
        inorder(root, k, res);
        return res;
    }

    // 带状态的中序遍历
    void inorder(TreeNode *root, int k, int& res) {
        if (root == nullptr) {
            return;  // 递归终止
        }

        // 递归遍历当前节点的左子树
        inorder(root->left, k, res);
        // 处理当前节点
        count++;
        if (count == k) {
            res = root->val;
            return;  // 已经找到结果, 直接返回
        }
        // 递归遍历当前节点的右子树
        if (count < k) {
            // 仅当没找到kth节点时, 才需继续遍历
            inorder(root->right, k, res);
        }
    }

private:
    int count;  // 记录已遍历的节点数
};
