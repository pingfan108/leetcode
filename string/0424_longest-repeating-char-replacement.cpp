/*
# 424. 替换后的最长重复字符
https://leetcode-cn.com/problems/longest-repeating-character-replacement/

给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
在执行上述操作后，找到包含重复字母的最长子串的长度。
注意：字符串长度 和 k 不会超过 104。

    示例 1：
输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
    示例 2：
输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
 */

// 解法1: 滑动窗口+哈希表
class Solution {
public:
    int characterReplacement(string s, int k) {
        //// 特殊case: 整个字符串都能被替换成重复字符的
        if (s.length() <= k+1) {
            return s.length();
        }

        //// 一般case: 滑动窗口+哈希表
        int fast = 0, slow = 0;  // 用作窗口左右边界的快慢指针
        int count[26] = {0};     // 记录字符出现次数的哈希表
        int maxcnt = 0;          // 已出现字符的历史最大重复次数
        // 外循环完成快指针(窗口右边界)的滑动
        for (; fast < s.length(); fast++) {
            // 扩展窗口右边界, 将边界新元素纳入(同时维护字符出现的频次和maxcnt)
            int id1 = s[fast] - 'A';
            count[id1]++;
            // 只有新进字符s[fast]的频次增加, 也只有它的频次才有可能挑战maxcnt
            maxcnt = std::max(maxcnt, count[id1]);

            // 内循环完成慢指针(窗口左边界)的滑动. 
            if (maxcnt + k < fast - slow + 1) {
                // 收缩窗口左边界, 将边界老元素移出(同时只维护字符出现的频次)
                // Note: 此处不会维护maxcnt! 因为maxcnt不是窗口内count[26]的当前
                //       最大值, 而是历史最大值. 详细的解释参考本题的官方题解.
                count[s[slow] - 'A']--;
                slow++;
            }
        }
        return fast - slow;  // 此时fast == s.length()

    }
};
