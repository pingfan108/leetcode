/*
# 160. 相交链表
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

 编写一个程序，找到两个单链表相交的起始节点。
 注意：
   - 如果两个链表没有交点，返回 null.
   - 在返回结果后，两个链表仍须保持原有的结构。
   - 可假定整个链表结构中没有循环。
   - 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 */
#include "include/list.h"

// 解法1: 快慢指针
// 思路: 将两个链表拼接, 合二为一 ==> 判断是否成环, 寻找环的起点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        // 将链表B拼接到链表A尾端
        ListNode *temp = headA;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = headB;

        // 快慢指针找拼接后是否有环
        ListNode *fast = headA;
        ListNode *slow = headA;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            // 快慢指针相遇说明拼接后有环, 也就是原始两链表有交点
            if (fast == slow) {
                // 继续找交点
                fast = headA;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                break;
            }
        }
        // 将两链表恢复原有的结构
        temp->next = nullptr;
        // 拼接后还能正常走到链表尾部, 说明原始两链表无交点
        return fast == slow ? fast : nullptr;
    }
};
