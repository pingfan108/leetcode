/*
# 143. 重排链表
https://leetcode-cn.com/problems/reorder-list/

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
    注意:
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

    示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
    示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 */

#include "include/list.h"

// 解法1: 另存为数组, 用下标访问
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // 将链表节点转存到一个数组中
        std::vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        // 用首尾双指针相向而行, 遍历数组完成重排
        int i = 0;
        int j = nodes.size() - 1;
        while (i < j) {
            nodes[i++]->next = nodes[j];
            nodes[j--]->next = nodes[i];
        }
        // 中点(长度奇数,i=j)或者中间靠右(长度偶数,i>j)为新的尾节点
        nodes[i]->next = nullptr;
    }
};

// 解法2: 快慢指针 + 链表逆序 + 二路归并

