/*
# 206. 反转链表
https://leetcode-cn.com/problems/reverse-linked-list/

反转一个单链表。
    示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
    进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 */
#include "include/list.h"

// 解法1: 循环迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;     // 指向当前节点
        ListNode *prev = nullptr;  // 指向curr的原始前序节点(因单链表没有前序指针)
        ListNode *temp;
        while (curr != nullptr) {
            temp = curr->next;  // 临时记录curr的原始后继节点
            curr->next = prev;  // 将原始前序节点改为新后继节点, 完成此段的反转
            prev = curr;        // 更新prev指针, 当前节点是下一个节点的原始前序
            curr = temp;        // 更新curr指针, 准备处理下一个节点
        }
        return prev;
    }
};

// 解法2: 递归大法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 递归终止条件: 到达最后一个节点(head->next == nullptr)
        // Note: 加上条件"head == nullptr"是为了防止一开始传进来的就是空链表
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 通过递归调用, 先把当前节点后面的子链表反转过来
        // 此步完成后, head->next即成为 newH子链表 的尾节点
        ListNode *newH = reverseList(head->next);
        // 将当前节点挂到上述子链表的末尾
        head->next->next = head;
        head->next = nullptr;
        return newH;
    }
};
