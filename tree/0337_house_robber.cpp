/*
# 337. 打家劫舍 III
https://leetcode-cn.com/problems/house-robber-iii/

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

    示例 1:
输入: [3,2,3,null,3,null,1]
     3
    / \
   2   3
    \   \ 
     3   1
输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

    示例 2:
输入: [3,4,5,1,3,null,1]
     3
    / \
   4   5
  / \   \ 
 1   3   1
输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
 */
#include "include/tree.h"

// 解法1: 递归 + 动态规划
// 思路:
// * 详见代码实现
class Solution {
public:
    int rob(TreeNode* root) {
        std::map<TreeNode*, int> dp;
        return robCore(root, dp);
    }

    // 返回curr节点能盗取的最大金额
    int robCore(TreeNode* curr, std::map<TreeNode*, int>& dp) {
        // 空节点没啥好偷的
        if (curr == NULL) {
            return 0;
        }
        // 如果之前已经计算过此节点的最大可盗取金额, 直接复用结果
        auto it = dp.find(curr);
        if (it != dp.end()) {
            return it->second;
        }

        // 假设盗取当前节点和其孙子节点, 计算其可盗取的最大金额
        int money = curr->val;
        if (curr->left != NULL) {
            money += (robCore(curr->left->left, dp) + robCore(curr->left->right, dp));
        }
        if (curr->right != NULL) {
            money += (robCore(curr->right->left, dp) + robCore(curr->right->right, dp));
        }
        // 假设略过当前节点, 盗取其子节点, 计算其可盗取的最大金额
        int money2 = robCore(curr->left, dp) + robCore(curr->right, dp);
        // 取两种选择的更大值为本子树的最终结果, 更新dp并返回
        int res = std::max(money, money2);
        dp[curr] = res;
        return res;
    }
};
