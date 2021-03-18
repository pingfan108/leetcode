/*
# 3. 无重复字符的最长子串
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
  请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
    示例 4:
输入: s = ""
输出: 0

    提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
 */

// 解法1: 滑动窗口+哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //// 特殊case: 一定没有重复字符的情况
        if (s.length() < 2) {
            return s.length();
        }

        //// 一般case: 滑动窗口+哈希表
        int fast = 0, slow = 0;         // 用作窗口左右边界的快慢指针
        std::unordered_set<char> dict;  // 记录窗口中已出现字符的哈希表
        int maxLen = 0;                 // 记录窗口滑动过程中的最大合法长度
        // 外循环完成快指针(窗口右边界)的滑动
        for (; fast < s.length(); fast++) {
            if (dict.find(s[fast]) != dict.end()) {
                // 新字符重复, 需调整窗口左边界, 剔除重复字符及其之前的字符
                // 内循环完成慢指针(窗口左边界)的滑动
                while (slow < fast) {
                    if (s[slow++] == s[fast]) {
                        break;
                    }
                    dict.erase(s[slow-1]);
                }
            } else {
                // 新字符不重复, 将其纳入窗口范围
                dict.insert(s[fast]);
            }
            // 尝试用当前(符合条件的)窗口的长度更新结果
            maxLen = std::max(maxLen, int(dict.size()));
        }
        return maxLen;
    }
};
