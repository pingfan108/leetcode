/*
# 876. 链表的中间结点
https://leetcode-cn.com/problems/middle-of-the-linked-list/

给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

    示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
    示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

    提示：
给定链表的结点数介于 1 和 100 之间。
 */

#include "include/list.h"

// 解法1: 快慢指针
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
