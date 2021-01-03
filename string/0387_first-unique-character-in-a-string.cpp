/*
# 387. 字符串中的第一个唯一字符
https://leetcode-cn.com/problems/first-unique-character-in-a-string/

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

    示例：
s = "leetcode"
返回 0
s = "loveleetcode"
返回 2

    提示：你可以假定该字符串只包含小写字母。
 */

// 解法1: 哈希表
class Solution {
public:
    int firstUniqChar(string s) {
        // 第一次遍历, 统计字符串s中每个字符出现的次数
        int count[26] = {0};  // 全小写字母, 哈希表可以简化
        for (char &c : s) {
            count[c - 'a']++;
        }
        // 第二次遍历, 依次检查每个字符出现的次数是否唯一
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        // 遍历结束, 没有唯一字符
        return -1;
    }
};
