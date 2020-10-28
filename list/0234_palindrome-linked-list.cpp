/*
# 234. 回文链表
https://leetcode-cn.com/problems/palindrome-linked-list/

请判断一个链表是否为回文链表。

    示例 1:
输入: 1->2
输出: false
    示例 2:
输入: 1->2->2->1
输出: true
    进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */

#include "include/list.h"

// 解法1: 转存数组 + 收尾指针
// 略

// 解法2: 递归
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 特殊case: 空链表和单节点链表一定是回文链表
        if (head == NULL || head->next == NULL) {
            return true;
        }
        // 初始化forward指针
        forward = head;
        // 递归检查链表是否为回文链表
        return isPalindromeCore(head);
    }

    bool isPalindromeCore(ListNode *head) {
        // 递归终止条件
        if (head == NULL) {
            return true;
        }

        if (!isPalindromeCore(head->next)        // 子链表不是回文链表
                || head->val != forward->val) {  // 当前节点不符合回文要求
            return false;
        }
        // 回溯(逆序第N+1个节点)之前, forward指针也指向下一个节点
        forward = forward->next;
        return true;
    }

private:
    ListNode *forward;  // 记录正序遍历的进度
};

// 解法3: 快慢指针 + 链表反转

