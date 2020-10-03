/*
# 2. 两数相加
https://leetcode-cn.com/problems/add-two-numbers/

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */

#include "include/list.h"

// 解法1: 递归大法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersCore(l1, l2, 0);
    }

    ListNode* addTwoNumbersCore(ListNode* l1, ListNode* l2, int more) {
        // 递归终止条件
        if (l1 == nullptr && l2 == nullptr && more == 0) {
            return nullptr;
        }

        // 计算当前节点的相加和(带上prev节点的进位情况)
        int val = more;
        if (l1 != nullptr) {
            val += l1->val;
            l1 = l1->next;  // l1移到下一节点
        }
        if (l2 != nullptr) {
            val += l2->val;
            l2 = l2->next;  // l2移到下一节点
        }
        auto curr = new ListNode(val % 10);
        // 递归求解两个链表下一节点的相加和结果
        curr->next = addTwoNumbersCore(l1, l2, val/10);
        return curr;
    }
};
