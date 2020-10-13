/*
# 24. 两两交换链表中的节点
https://leetcode-cn.com/problems/swap-nodes-in-pairs/

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

    示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
    示例 2：
输入：head = []
输出：[]
    示例 3：
输入：head = [1]
输出：[1]

    提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
 */

#include "include/list.h"

// 解法1: 递归大法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 递归终止条件
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 交换当前group内的两个节点
        ListNode *temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        // 返回新的链表头节点
        return temp;
    }
};

// 解法2: 迭代大法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;  // 当前节点(当前group的一节点)
        ListNode* next = NULL;  // 当前节点的后一节点(当前group的二节点)
        ListNode* prev = NULL;  // 当前节点的前一节点(上一group的二节点)
        // 两个节点一个group, 循环遍历链表
        while (curr != NULL && curr->next != NULL) {
            // 将当前group与前一个group拼接
            next = curr->next;
            if (prev != NULL) {
                prev->next = next;
            } else {
                // 这是第一个group, 没有prev group, 无需拼接但需重置头指针
                head = next;
            }
            // 将当前group与后一个group拼接
            curr->next = next->next;
            // 交换当前group内的两个节点
            next->next = curr;
            // 迭代循环变量
            prev = curr;
            curr = next->next->next;
        }
        // 返回新的链表头节点
        return head;
    }
};
