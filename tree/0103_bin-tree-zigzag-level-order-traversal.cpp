/*
# 103. 二叉树的锯齿形层序遍历
https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

    例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：
[
  [3],
  [20,9],
  [15,7]
]
 */

// 解法1: 层序遍历 + 双栈
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 结果数组
        vector<vector<int>> res;
        // 双栈, 一个记录当前层未遍历的节点, 另一个缓存下一层的节点
        vector<stack<TreeNode*> > sts(2);
        int idx = 0;          // 指向当前栈
        sts[idx].push(root);  // 根节点入当前栈
        // 遍历所有的层
        while (sts[idx].size()) {  // 检查新的一层是否为空
            vector<int> tmp;       // 记录当前层被遍历的节点
            int oth = idx ^ 1;     // 指向另一个栈(当前为空)
            // 遍历当前层所有的节点
            while (sts[idx].size()) {
                auto curr = sts[idx].top();
                if (curr != NULL) {
                    if (oth) {
                        // 奇数层的节点从左往右入栈
                        sts[oth].push(curr->left);
                        sts[oth].push(curr->right);
                    } else {
                        // 偶数层的节点从右到左入栈
                        sts[oth].push(curr->right);
                        sts[oth].push(curr->left);
                    }
                    tmp.push_back(curr->val);
                }
                sts[idx].pop();
            }
            if (tmp.empty()) {
                break;
            }
            // 记录当前层的遍历结果
            res.push_back(tmp);
            // 切换到下一层
            idx = oth;
        }
        return res;
    }
};
