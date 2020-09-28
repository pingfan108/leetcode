/*
# 117. 填充每个节点的下一个右侧节点指针 II
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

给定一个二叉树
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

    进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

    示例：
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

提示：
树中的节点数小于 6000
-100 <= node.val <= 100
 */

#include "include/tree.h"

// 解法1: 层序遍历(计算层次)
// 思路: 见代码
class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> nodes;  // 保存已处理节点的子节点
        nodes.push(root);         // 根节点入队
        // 外循环遍历所有层次
        while (!nodes.empty()) {
            Node* prev = NULL;     // 记录当前层次当前节点的左侧节点
            int n = nodes.size();  // 记录当前层次的节点数
            // 内循环遍历当前层次所有节点
            for (int i = 0; i < n; i++) {
                // 取出当前节点
                auto curr = nodes.front();
                nodes.pop();
                if (curr == NULL) {
                    continue;
                }
                // 记录当前节点的左右子节点
                nodes.push(curr->left);
                nodes.push(curr->right);
                // 设置当前节点的左侧节点的next指针
                if (prev != NULL) {
                    prev->next = curr;
                }
                prev = curr;
            }
        }
        return root;
    }
};
