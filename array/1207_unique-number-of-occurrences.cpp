/*
# 1207. 独一无二的出现次数
https://leetcode-cn.com/problems/unique-number-of-occurrences/

给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

    示例 1：
输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
    示例 2：
输入：arr = [1,2]
输出：false
    示例 3：
输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true

    提示：
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
 */

// 解法1: 哈希表
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 统计arr中每个数字出现的次数, 记录在哈希表1
        std::map<int, int> count;
        for (auto &num : arr) {
            auto it = count.find(num);
            if (it != count.end()) {
                it->second++;
            } else {
                count[num] = 1;
            }
        }

        // 遍历统计结果, 将所有'次数'放进一个新的哈希表2
        std::set<int> hash;
        for (auto it = count.begin(); it != count.end(); it++) {
            hash.insert(it->second);
        }
        // 如果出现次数不重复, 两个哈希表的大小应该相等
        return hash.size() == count.size();
    }
};
