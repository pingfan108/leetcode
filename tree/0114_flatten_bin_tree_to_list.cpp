/*
# 114. 二叉树展开为链表
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

给定一个二叉树，原地将它展开为一个单链表。
例如，给定二叉树
    1
   / \
  2   5
 / \   \
3   4   6

将其展开为：
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */
#include "include/tree.h"

// 解法1: 转存数组 + 遍历数组
// 思路:
// * 先前序遍历二叉树将遍历结果记录到一维数组中, 再遍历数组修改指针指向.
// 时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        // 先通过前序遍历将此二叉树的所有节点依次转存到一维数组中
        std::vector<TreeNode*> nodes;
        preOrder(root, nodes);
        // 遍历该一维数组, 依次修改所有节点的左右指针
        if (nodes.size() <= 1) return;
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i+1];
        }
    }

    // 前序遍历此二叉树, 将其所有节点依次转存到一维数组中
    void preOrder(TreeNode *root, std::vector<TreeNode*>& nodes) {
        if (root == NULL) return;
        nodes.push_back(root);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }
};

// 解法2: 基于递归的逐步翻转拼接
// 思路:
// * 递归将左右子树分别展开为左右子链表, 将右子链表拼接到左子链表尾部;
// * 将root节点左指针置空, 右指针指向上一步拼接而成的完整链表;
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // 递归分别完成左右子树的链表展开
        flatten(root->right);  // 将右子树展开为链表, 简称右子链表
        if (root->left == nullptr) {
            return;  // 左子树为空, 则转换直接结束
        }
        flatten(root->left);  // 将左子树展开为链表, 简称左子链表

        // 完成root和左子链表&&右子链表的拼接
        TreeNode *tmp = root->left;
        while (tmp->right != nullptr) {  // 找到左子链表的尾部
            tmp = tmp->right;
        }
        tmp->right = root->right;  // 将 右子链表 拼接到 左子链表 尾部
        root->right = root->left;  // root右指针指向拼接而成的完整链表
        root->left = nullptr;      // root左指针需要置空
    }
};

// 解法3: 基于迭代的原地转换
// 思路:
// * 用一个指针记录当前遍历的节点，初始指向根节点;
// * 如果当前节点左子树不为空, 将右子树拼接到左子树的最右子节点上, 再将左子树改
//   为右子树(至此, 当前节点的左子节点为空);
// * 将当前指针移向当前节点的右子节点, 直至右子节点为空.
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            // 左子树不为空, 需将右子树拼接到左子树的最右子节点上, 再将左改右
            if (root->left != nullptr) {
                auto tmp = root->left;
                while (tmp->right != nullptr) {  // 找到root左子树的最右节点
                    tmp = tmp->right;
                }
                tmp->right = root->right;  // 将右子树拼接到左子树的最右节点
                root->right = root->left;  // 将root的左子树改为右子树
                root->left = nullptr;      // 将root的左子树置空
            }
            root = root->right;            // 处理下一个子节点
        }
    }
};
