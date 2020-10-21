/*
#19. 删除链表的倒数第N个节点
https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
    说明：
给定的 n 保证是有效的。
    进阶：
你能尝试使用一趟扫描实现吗？
 */

#include "include/list.h"

// 解法1: 快慢指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        // fast指针先走n步, 使得fast和slow之间的步调差刚好为n
        while (n--) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            // 特殊case: 原始链表总长度为n, 需要删除的正是原来的头节点
            return head->next;
        }

        // fast和slow同步调后移, fast指针走到链表尾节点的时候, slow指针刚好指向
        // 链表的倒数第n+1个节点
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除slow指针的next节点, 新链表的头节点不变
        slow->next = slow->next->next;
        return head;
    }
};
