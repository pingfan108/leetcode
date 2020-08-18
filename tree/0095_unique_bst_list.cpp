/*
# 95. 不同的二叉搜索树 II
https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

    示例：
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：以上的输出对应以下 5 种不同结构的二叉搜索树：
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

    提示：
0 <= n <= 8
 */
#include "include/tree.h"

// 解法1: 递归求解
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> res;
        if (n == 0) {
            return res;  // 其实我感觉不用, 但是这样写才能通过n==0的测试用例
        }
        return generateTreesCore(1, n);
    }

    vector<TreeNode*> generateTreesCore(int beg, int end) {
        std::vector<TreeNode*> res;
        if (beg > end) {
            // 空二叉树
            res.push_back(nullptr);
            return res;
        } else if (beg == end) {
            // 单节点二叉树
            auto root = new TreeNode(beg);
            res.push_back(root);
            return res;
        }
        // 节点数大于2的情况, 遍历root节点为[beg,end]的所有可能
        for (int i = beg; i <= end; i++) {
            // root节点为i的情况下, 左子树和右子树的所有可能都可以由递归得到
            auto lTrees = generateTreesCore(beg, i-1);
            auto rTrees = generateTreesCore(i+1, end);
            // 遍历所有可能的左子树和右子树, 得到所有可能的组合
            for (auto &l : lTrees) {
                for (auto &r : rTrees) {
                    auto root = new TreeNode(i, l, r);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

// 解法2: 动态规划
// 思路:
// * 参考, https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};  // 其实我感觉不用, 但是这样写才能通过n==0的测试用例
        }

        //// Step1: 创建状态转移数组, dp[i]表示由[1,i]为节点所组成的BST集合
        std::vector<std::vector<TreeNode*> > dp(n+1);
        //// Step2: 初始化 i==0 作为第一推动力
        dp[0] = {nullptr};
        //// Step3: 长度从1到n, 依次填充状态转移数组
        for (int len = 1; len <= n; len++) {
            std::vector<TreeNode*> tmp;
            // 遍历[1,len]闭区间内所有节点为root的情况
            for (int i = 1; i <= len; i++) {
                // root节点为i的情况下, 左子树的集合可由早期确定的dp[j]直接得到
                auto lTrees = dp[i-1];
                // root节点为i的情况下, 由子树的集合可由早期确定的dp[j]间接得到
                auto rTrees = dp[len-i];
                for (auto &left : lTrees) {
                    for (auto &right : rTrees) {
                        // 右子树可以由需要做偏移复制
                        auto clone = cloneWithOffset(right, i);
                        auto root = new TreeNode(i, left, clone);
                        tmp.push_back(root);
                    }
                }
            }
            dp[len] = tmp;
        }
        //// Step4: dp[n]即为题解
        return dp[n];
    }

    // 带val增量(offset)的BST复制
    TreeNode* cloneWithOffset(TreeNode* root, int offset) {
        if (root == nullptr) return nullptr;

        auto res = new TreeNode(root->val + offset);
        res->left = cloneWithOffset(root->left, offset);
        res->right = cloneWithOffset(root->right, offset);
        return res;
    }
};
