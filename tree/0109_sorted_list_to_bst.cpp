/*
# 109. 有序链表转换二叉搜索树
https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5
 */
#include "include/list.h"
#include "include/tree.h"

// 解法1: 递归求解 + 快慢指针
// 思路:
// * 类似于第108题, 将输入链表二分, 以链表中点为BST根节点, 再递归地将两段子链表
//   分别转换为根节点的左右子树即可;
// * 对于输入的单链表, 无法直接二分, 可以借助快慢指针法找到中点, 然后二分.
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 特殊case: 输入链表为空
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* l1 = nullptr;  // 前半段链表的头指针
        ListNode* l2 = nullptr;  // 后半段链表的头指针
        // 将输入链表分为三段: 前半段, 中点mid, 后半段
        auto mid = FindListMidAndCut(head, &l1, &l2);
        // 以mid节点作为所求BST的根节点
        auto root = new TreeNode(mid->val);
        // 递归地将前半段链表转为root节点的左子树
        root->left = sortedListToBST(l1);
        // 递归地将后半段链表转为root节点的右子树
        root->right = sortedListToBST(l2);
        // 返回root节点即可
        return root;
    }

    // 查找链表的中点, 同时将链表从中点断开
    ListNode* FindListMidAndCut(ListNode *head, ListNode **l1, ListNode **l2) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;  // 记录慢指针的前一个节点, 用以断开链表
        // 基于快慢指针法查找链表的中点
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 根据查找结果将输入链表分为三段: 前半段, 中点(slow), 后半段
        *l1 = head;        // 前半段, head ==> slow->prev
        *l2 = slow->next;  // 后半段, slow->next ==> tail
        if (prev == nullptr) {
            // 说明中点(slow)和head重合, 前半段链表应置空
            *l1 = nullptr;
        } else {
            // 前半段链表非空时, 需和后面断开
            prev->next = nullptr;
        }
        // 返回中点
        return slow;
    }
};
