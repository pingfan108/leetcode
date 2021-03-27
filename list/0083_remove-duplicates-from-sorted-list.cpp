/*
# 83. 删除排序链表中的重复元素
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

    示例 1:
输入: 1->1->2
输出: 1->2
    示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
 */

// 解法1: 快慢指针法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 特殊case: 肯定没有重复元素的情况
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 一般case: 用快慢指针一轮遍历
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = NULL;  // 断开与重复元素的链接
        return head;
    }
};
