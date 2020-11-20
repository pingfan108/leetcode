/*
# 148. 排序链表
https://leetcode-cn.com/problems/sort-list/

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
    进阶：
你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

    示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]
    示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
    示例 3：
输入：head = []
输出：[]

    提示：
链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
 */

// 解法1: 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 特殊case: 少于两个节点, 不用排序(也是递归终止条件)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 快慢指针找到链表中点 
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;  // 指向slow指针的前一个节点
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 从链表中点断开, 一分为二
        prev->next = nullptr;
        // 分别对两个子链表排序
        head = sortList(head);
        slow = sortList(slow);
        return merge(head, slow);
    }

    // 合并两个有序链表
    ListNode* merge(ListNode* h1, ListNode* h2) {
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;

        ListNode* head;
        if (h1->val < h2->val) {
            head = h1;
            head->next = merge(h1->next, h2);
        } else {
            head = h2;
            head->next = merge(h1, h2->next);
        }
        return head;
    }
};

// 解法2: 快速排序
// 当输入链表原本就是升序排列的超长链表时, 会超时
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 特殊case: 少于两个节点, 不用排序(也是递归终止条件)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 基于分区函数将链表分为相对有序的两部分
        ListNode* h2 = partiton(head);  // h2是较小的一半
        if (h2 == nullptr) {
            head->next = sortList(head->next);
            return head;
        }
        h2 = sortList(h2);
        ListNode* temp = h2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;
        head->next = sortList(head->next);
        return h2;
    }

    // 将指定链表分为相对有序的两个子链表
    ListNode* partiton(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }  
        ListNode *curr1 = head;
        ListNode *head2 = nullptr, *curr2 = nullptr;
        ListNode *temp = head->next;
        while (temp != nullptr) {
            if (temp->val < head->val) {
                if (head2 == nullptr) {
                    head2 = temp;
                } else {
                    curr2->next = temp;
                }
                curr2 = temp;
            } else {
                curr1->next = temp;
                curr1 = temp;
            }
            temp = temp->next;
        }
        if (curr1) curr1->next = nullptr;
        if (curr2) curr2->next = nullptr;
        return head2;
    }
};

// 解法3: 插入排序
// 直接参见0147, 需使用上一步插入位置记忆优化
