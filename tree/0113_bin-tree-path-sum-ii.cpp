/*
# 113. 路径总和 II
https://leetcode-cn.com/problems/path-sum-ii/

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。

    示例:
给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
 */

#include "include/tree.h"

// 解法1: 带状态的前序遍历
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // 清空pathList, 防止多次调用之间的影响
        pathList.clear();
        // 搜索二叉树的所有路径, 将符合条件的路径存放在pathList
        std::vector<int> path;
        pathSumCore(root, sum, path);
        return pathList;
    }

    // 基于前序遍历的二叉树路径搜索
    void pathSumCore(TreeNode* curr, int sum, std::vector<int>& path) {
        // 递归终止
        if (curr == NULL) {
            // 提前终止无效路径
            return;
        } else if (curr->left == NULL && curr->right == NULL
                && curr->val == sum) {
            // 找到符合条件的路径: 路径和==目标和 && 到达叶子节点
            std::vector<int> res(path);
            res.push_back(curr->val);
            pathList.push_back(res);
            return;
        }

        // 递归搜索当前节点的左子树和右子树
        path.push_back(curr->val);   // 搜索前将当前节点加入记忆路径
        sum -= curr->val;
        pathSumCore(curr->left, sum, path);
        pathSumCore(curr->right, sum, path);
        path.erase(path.end() - 1);  // 退出前将当前节点从记忆路径删除
    }

private:
    std::vector<std::vector<int>> pathList;
};
