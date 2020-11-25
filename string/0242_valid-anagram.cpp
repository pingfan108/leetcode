/*
# 242. 有效的字母异位词
https://leetcode-cn.com/problems/valid-anagram/

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

    示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
    示例 2:
输入: s = "rat", t = "car"
输出: false

    说明:
你可以假设字符串只包含小写字母。
    进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 */

// 解法1: 哈希表
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 特殊case: 长度不同必定不是(只为加速)
        if (s.length() != t.length()) {
            return false;
        }

        int dict[26] = {0};
        // 累加s中各个字符出现的次数
        for (auto &c : s) {
            dict[c-'a']++;
        }
        // 累减t中各个字符出现的次数
        for (auto &c : t) {
            dict[c-'a']--;
        }
        // 检查各个字符最终的统计结果是否为0
        for (int i = 0; i < 26; i++) {
            if (dict[i] != 0) {
                // >0说明s中有多出的字符; <0说明t中有多出的字符
                return false;
            }
        }
        return true;
    }
};
