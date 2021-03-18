/*
# 159. 至多包含两个不同字符的最长子串
https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/

给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t ，并返回该子串的长度。
    示例 1:
输入: "eceba"
输出: 3
解释: t 是 "ece"，长度为3。
    示例 2:
输入: "ccaabbb"
输出: 5
解释: t 是 "aabbb"，长度为5。
 */

// 解法1: 滑动窗口+哈希表
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int fast = 0, slow = 0;    // 用作窗口左右边界的快慢指针
        std::map<char, int> dict;  // 记录窗口中已出现字符及频次的哈希表
        int maxLen = 0;            // 记录窗口滑动过程中的最大合法长度
        // 外循环完成快指针(窗口右边界)的滑动(同时需检查窗口内不同字符数是否超2)
        for (; fast < s.length(); fast++) {
            // 扩展窗口右边界, 将边界新元素纳入
            auto iter = dict.find(s[fast]);
            if (iter != dict.end()) {
                // 新元素是当前窗口内已经存在的字符, 增加频次计数就好
                iter->second++;
            } else {
                // 新元素是当前窗口内本不存在的字符, 需要检查不同字符数是否超2
                dict[s[fast]] = 1;
                // 内循环完成慢指针(窗口左边界)的滑动(直到窗口内不同字符数减为2)
                while (dict.size() > 2 && slow < fast) {
                    if (--dict[s[slow]] == 0) {
                        dict.erase(s[slow]);
                    }
                    slow++;
                }
            }
            // 尝试用当前(符合条件的)窗口的长度更新结果
            maxLen = std::max(maxLen, fast - slow + 1);
        }
        return maxLen;
    }
};
