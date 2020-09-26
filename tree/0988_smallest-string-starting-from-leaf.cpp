/*
# 988. 从叶结点开始的最小字符串
https://leetcode-cn.com/problems/smallest-string-starting-from-leaf/

给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个从 0 到 25 的值，分别代表字母 'a' 到 'z'：值 0 代表 'a'，值 1 代表 'b'，依此类推。
找出按字典序最小的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。
（小贴士：字符串中任何较短的前缀在字典序上都是较小的：例如，在字典序上 "ab" 比 "aba" 要小。叶结点是指没有子结点的结点。）

    示例 1：
输入：[0,1,2,3,4,3,4]
输出："dba"
    示例 2：
输入：[25,1,3,1,3,0,2]
输出："adz"
    示例 3：
输入：[2,2,1,null,1,0,null,0]
输出："abc"

    提示：
给定树的结点数介于 1 和 8500 之间。
树中的每个结点都有一个介于 0 和 25 之间的值。
 */

#include "include/tree.h"

// 解法1: 带状态的前序遍历
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        // 清空result, 防止多次调用之间的影响
        result.clear();
        // 搜索二叉树的所有路径, 将最小字符串存放在result
        std::string path;
        smallestFromLeafCore(root, path);
        return result;
    }

    // 基于前序遍历的二叉树路径搜索
    void smallestFromLeafCore(TreeNode* curr, std::string path) {
        // 递归终止
        if (curr == NULL) {
            return;
        }

        path.push_back(curr->val + 'a');  // 将当前节点加入记忆路径
        if (curr->left == NULL && curr->right == NULL) {
            // 当前节点为叶子结点, 尝试更新result
            std::string revPath(path);
            reverse(revPath.begin(), revPath.end());
            if (result.empty() || revPath < result) {
                result = revPath;
            }
        } else {
            // 还未到叶子节点, 递归搜索当前节点的左子树和右子树
            smallestFromLeafCore(curr->left, path);
            smallestFromLeafCore(curr->right, path);
        }
        path.erase(path.end() - 1);  // 退出前将当前节点从记忆路径删除
    }

private:
    std::string result;
};
