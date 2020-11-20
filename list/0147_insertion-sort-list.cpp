/*
# 147. 对链表进行插入排序
147. 对链表进行插入排序
https://leetcode-cn.com/problems/insertion-sort-list/

对链表进行插入排序。
插入排序算法：
* 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
* 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
* 重复直到所有输入数据插入完为止。

    示例 1：
输入: 4->2->1->3
输出: 1->2->3->4
    示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5
 */

// 解法1: 增加额外的头节点
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // 特殊case: 单个节点不用排序
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // 创建额外的头节点方便操作
        ListNode* head2 = new ListNode(-1);
        // 遍历原始链表
        ListNode* curr1 = head;  // 原始链表当前节点
        ListNode* next1;         // 原始链表下一节点
        ListNode* prev2;         // 新链表插入位置前一节点
        while (curr1 != NULL) {
            // 缓存原始链表的下一个节点
            next1 = curr1->next;
            // 遍历新链表, 找到合适的插入位置
            /* 复用上一轮的插入位置, 减少比较次数, 可以加速一倍
            if (prev2 && prev2->next->val < curr1->val) {
                prev2 = prev2->next;
            } else {
                prev2 = head2;
            }*/
            prev2 = head2;
            while (prev2->next != NULL && prev2->next->val < curr1->val) {
                prev2 = prev2->next;
            }
            // 将原始链表当前节点插入新链表
            curr1->next = prev2->next;
            prev2->next = curr1;
            // 继续处理原始链表的下一个节点
            curr1 = next1;
        }
        // 返回新链表的头指针(头节点的next指针)
        head = head2->next;
        delete head2;
        return head;
    }
};

// 解法2: 直接处理
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // 特殊case: 单个节点不用排序
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head->next;
        ListNode* head2 = head;
        head2->next = NULL;
        // 遍历原始链表
        while (curr != NULL) {
            // 缓存原始链表的下一个节点
            ListNode* next = curr->next;
            // 遍历新链表, 找到合适的插入位置
            ListNode* prev2 = NULL;
            ListNode* curr2 = head2;
            while (curr2 != NULL && curr2->val < curr->val) {
                prev2 = curr2;
                curr2 = curr2->next;
            }
            // 将原始链表当前节点插入新链表
            curr->next = curr2;
            if (prev2) {
                prev2->next = curr;
            } else {
                head2 = curr;
            }
            // 继续处理原始链表的下一个节点
            curr = next;
        }
        return head2;
    }
};
