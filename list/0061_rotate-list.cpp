/*
# 61. 旋转链表
https://leetcode-cn.com/problems/rotate-list/

给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

    示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
    示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]

    提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
 */

#include "include/list.h"

// 解法: 快慢指针
// 思路:
// 1. 基于快慢指针找到链表倒数第k+1个节点, 从此处将链表一切为二, 交换顺序即可
// 2. Note!!! k可能为0, 也可能远大于链表长度, 需要注意k的边界条件处理
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;

        // Step1: 计算链表长度len, 基于len规整k, 避免k>len的情况
        int len = 0;  // 记录链表长度
        while (fast != nullptr) {
            len++;
            fast = fast->next;
        }
        k = len > 0 ? (k % len) : 0;
        if (len == 0 || k == 0) return head;

        // Step2: 快慢指针找倒数第k+1个节点
        fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step3: 在slow和slow->next之间剪一刀, 交换两个子链表的顺序
        ListNode *temp = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return temp;
    }
};
