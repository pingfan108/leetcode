/*
# 94. 二叉树的中序遍历
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

给定一个二叉树，返回它的中序 遍历。

	示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [1,3,2]
	进阶: 
递归算法很简单，你可以通过迭代算法完成吗？
 */
#include "include/tree.h"

// 解法1: 基于调用栈递归实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorderTraversalCore(root, res);
        return res;
    }

    void inorderTraversalCore(TreeNode* root, std::vector<int> &res) {
        if (root == NULL) return;
        
        inorderTraversalCore(root->left, res);
        res.push_back(root->val);
        inorderTraversalCore(root->right, res);
    }
};

// 解法2: 基于辅助栈的迭代实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;      // 记录中序遍历的结果
        std::stack<TreeNode*> st;  // 辅助栈
        auto curr = root;
        while (curr != NULL || !st.empty()) {
            // 将当前节点最左子节点之前的所有节点都入栈
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            // 以栈顶节点(即当前未遍历节点中的最左子节点)为新的当前节点
            curr = st.top();
            res.push_back(curr->val);
            st.pop();
            // 继续处理 新当前节点 的右子树
            curr = curr->right;
        }
        return res;
    }
};
