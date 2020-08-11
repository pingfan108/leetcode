/*
# 25. K 个一组翻转链表
https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

    示例：
给你这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

    说明：
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 */
#include "list.h"

// 解法1: 循环迭代
// 思路:
// * 每1轮从当前节点开始, 往后取最多k个节点, 作为1个group;(使用两个额外的指针,
//   分别记录上一个group的尾节点和下一个group的头节点)
// * 若当前group取够了k个节点, 对当前group内节点组成的子链表做单链表翻转; 反之,
//   当前group保持原有顺序即可; 将当前group处理后的结果拼接到上一个group后面;
// * 继续处理下一个group, 直到结束.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 特殊case: 无需做翻转的情况
        if (head == NULL || k == 1) {
            return head;
        }

        ListNode* curr = head;    // 指向当前group的头节点
        ListNode* newH = NULL;    // 指向翻转完成后新链表头节点
        ListNode* pgTail = NULL;  // 指向上一个group尾节点(prevGroupTail)
        ListNode* ngHead = NULL;  // 指向下一个group头节点(nextGroupHead)
        do {
            // Step1: 检查剩余节点数是否还够一个group
            if (!findNextKGroup(curr, k, &ngHead)) {
                break;  // 尾部不够一个group的剩余节点保持原有顺序即可
            }
            // Step2: 针对当前group直接做单链表翻转, 并处理翻转后的结果
            auto temp = reverseOneGroup(curr);
            if (pgTail != NULL) {
                // 这是中间的group, 接到上一个group尾节点后
                pgTail->next = temp;
            } else {
                // 这是第一个group, 记录翻转完成后新链表的头节点
                newH = temp;
            }
            // Step3: 流转到下一个group
            pgTail = curr;
            curr = ngHead;
        } while (curr != NULL);
        // 将原链表尾部不够一个group的剩余节点直接接在最后一个翻转过的group后面
        if (pgTail) {
            pgTail->next = curr;
        }
        return newH == NULL ? head : newH;
    }

    // 寻找下一个group的头节点
    // 返回: 找到了返回true, 否则返回false
    bool findNextKGroup(ListNode* head, int k, ListNode** ngHead) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int i = 0;
        while (i < k) {
            if (curr == NULL) {
                return false;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        *ngHead = curr;
        prev->next = NULL;  // 这是为了便于reverseOneGroup()处理的时候做结束判断
        return true;
    }

    // 翻转一个长度大于1的单链表
    // 返回: 翻转过后新链表的头节点
    ListNode* reverseOneGroup(ListNode* head) {
        ListNode *newH, *curr, *temp;
        newH = head;
        curr = head->next;
        do {
            temp = curr->next;
            curr->next = newH;
            newH = curr;
            curr = temp;
        } while (curr != NULL);
        //head->next = NULL;  // unneccessary
        return newH;
    }
};
