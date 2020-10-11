/*
# 142. 环形链表 II
https://leetcode-cn.com/problems/linked-list-cycle-ii/

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。

    示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
    示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
    示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

    进阶：
你是否可以不用额外空间解决此题？
 */

#include "include/list.h"

// 解法2: 快慢指针法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        // 遍历链表
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            // 快慢指针相遇说明有环, 继续寻找入环起点
            if (fast == slow) {
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        // 环形链表的遍历是个死循环, 跳出循环说明无环
        return NULL;
    }
};

// 解法1: 哈希表记忆法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 用一个额外的哈希表记录已经访问过的节点
        std::unordered_set<ListNode*> nodes;
        // 遍历链表
        while (head != NULL) {
            if (nodes.find(head) != nodes.end()) {
                return head;  // 第一个重复的节点就是入环的第一个节点
            }
            nodes.insert(head);
            head = head->next;
        }
        // 环形链表的遍历是个死循环, 跳出循环说明无环
        return NULL;
    }
};
