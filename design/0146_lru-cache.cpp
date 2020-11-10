/*
# 146. LRU缓存机制
https://leetcode-cn.com/problems/lru-cache/

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：
    * LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
    * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
    * void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

    进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

    示例：
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]
解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

    提示：
1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
最多调用 3 * 104 次 get 和 put
 */

// 解法: 哈希链表(doubly_linked_list + unordered_map)
// 定义双向链表节点结构
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

// LRUCache类的实现
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        num = 0;

        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // 在哈希表中查找key
        auto it = dict.find(key);
        if (it == dict.end()) {
            return -1;  // cache中没有, 直接返回-1
        }
        // 将节点移动到双链表的队首
        pickout(it->second);        // 从当前位置摘出
        insertAsFirst(it->second);  // 插入队首
        // 返回节点的值
        return it->second->val;
    }
    
    void put(int key, int value) {
        Node* node;
        // 在哈希表中查找key
        auto it = dict.find(key);
        if (it == dict.end()) {
            node = new Node(key, value);
            if (num >= cap) {
                removeEnd();    // 当前容量已经到达上限, 需移除最后一个节点
                num--;          // 计数器-1
            }
            dict[key] = node;    // 将新节点加入哈希表, 方便之后查询
            num++;              // 计数器+1
        } else {
            node = it->second;
            node->val = value;  // 更新节点的value
            pickout(node);      // 将节点从当前位置摘出
        }
        insertAsFirst(node);    // 将新节点/更新后的节点放到队首
    }

private:
    // 将指定节点从当前位置前后断开
    void pickout(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    // 将指定节点插入到队首
    void insertAsFirst(Node* curr) {
        head->next->prev = curr;
        curr->next = head->next;
        head->next = curr;
        curr->prev = head;
    }

    // 将最后一个节点移除并释放
    void removeEnd() {
        auto end = tail->prev;
        dict.erase(end->key);  // 从哈希表中移除
        pickout(end);         // 从双向链表中移除
        delete end;           // 释放节点
    }

private:
    int cap;     // Cache的最大容量, 双向链表允许的的最大节点数
    int num;     // Cache的当前大小
    Node* head;  // 双向链表的头节点
    Node* tail;  // 双向链表的尾节点
    std::unordered_map<int, Node*> dict;  // key与双向链表节点的映射
};
