/*
# 381. O(1) 时间插入、删除和获取随机元素 - 允许重复
https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

    示例:
// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();
// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);
// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);
// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);
// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();
// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);
// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();
 */

// 解法1: vector + unordered_map
// 思路:
// * 将元素存到vector中, 满足O(1)插入且允许重复, 满足O(1)随机获取且概率分布符合
// * 额外用unordered_map存放val和其索引集合的映射关系, 满足O(1)删除
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        // 初始化随机数种子
        srand((int)time(0));
    }
    
    /** Inserts a value to the collection.
     * Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // 将元素加入列表
        vals.push_back(val);
        // 记录新加入元素的索引
        val2Index[val].insert(vals.size() - 1);
        return val2Index[val].size() == 1;
    }
    
    /** Removes a value from the collection.
     * Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 检查给定元素值是否存在
        auto it = val2Index.find(val);
        if (it == val2Index.end()) {
            return false;  // 不存在, 直接返回
        }

        // 取出该元素值的任意一个索引idx, 并将idx从索引集合中清除
        int idx = *(it->second.begin());
        if (it->second.size() == 1) {
            val2Index.erase(it);    // 这是最后一个索引, 直接清除这个元素
        } else {
            it->second.erase(idx);  // 只清除这个索引
        }
        // 将待删除元素和元素列表的尾部元素交换(已在尾部跳过此步)
        if (idx != vals.size() - 1) {
            // 将元素列表中最后一个元素M交换到idx
            vals[idx] = vals.back();
            // 修改元素M对应索引集合
            val2Index[vals.back()].erase(vals.size() - 1);
            val2Index[vals.back()].insert(idx);
        }
        // 删除元素列表的尾部元素即可
        vals.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (vals.empty()) {
            return INT_MIN;  // 表示集合为空的特殊值
        }
        return vals[rand() % vals.size()];
    }

private:
    // 元素列表
    std::vector<int> vals;
    // 元素值和索引列表的映射表
    std::unordered_map<int, std::unordered_set<int>> val2Index;
};
