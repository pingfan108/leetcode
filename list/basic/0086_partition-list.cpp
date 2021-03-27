/*
# 86. 分隔链表
https://leetcode-cn.com/problems/partition-list/

给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。

    示例：
输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5
 */
#include "include/list.h"

// 解法1: 链表遍历
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *h1 = NULL, *prev1 = NULL;
        ListNode *h2 = NULL, *prev2 = NULL;
        ListNode *curr = head;
        while (curr != NULL) {
            if (curr->val < x) {
                if (prev1 != NULL) {
                    prev1->next = curr;
                } else {
                    h1 = curr;
                }
                prev1 = curr;
            } else {
                if (prev2 != NULL) {
                    prev2->next = curr;
                } else {
                    h2 = curr;
                }
                prev2 = curr;
            }
            curr = curr->next;
        }

        if (h1 == NULL || h2 == NULL) {
            return head;
        }
        prev1->next = h2;
        prev2->next = NULL;
        return h1;
    }
};
