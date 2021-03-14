/*
# 76. 最小覆盖子串
https://leetcode-cn.com/problems/minimum-window-substring/

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

    示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
    示例 2：
输入：s = "a", t = "a"
输出："a"

    提示：
1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

    进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// 解法1: 滑动窗口+哈希表
class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if (s.length() < t.length()) {
            return res;
        }

        // 根据目标串t构造needs字典
        std::unordered_map<char, int> needs;
        int needCnt = t.length();
        for (auto &c : t) {
            auto iter = needs.find(c);
            if (iter == needs.end()) {
                needs[c] = 1;
            } else {
                iter->second++;
            }
        }

        // 基于滑动窗口遍历源串s
        int fast = 0, slow = 0;  // 用作窗口左右边界的快慢指针
        // 外循环完成快指针(窗口右边界)的滑动
        for (; fast < s.length(); fast++) {
            // 扩展窗口右边界, 将边界新元素纳入(同时需要检查更新
            // 当前窗口内的子串对t的覆盖程度)
            auto it1 = needs.find(s[fast]);
            if (it1 == needs.end()) {
                continue;
            } else if (it1->second-- > 0) {
                needCnt--;
            }

            // 内循环完成慢指针(窗口左边界)的滑动
            while (needCnt == 0 && slow <= fast) {
                // 尝试用当前(符合条件的)窗口覆盖的子串更新结果
                int sublen = fast - slow + 1;
                if (res.empty() || sublen < res.length()) {
                    res = s.substr(slow, sublen);
                }
                // 收缩窗口左边界, 将边界老元素移出(同时需要检查更新
                // 当前窗口内的子串对t的覆盖程度)
                auto it2 = needs.find(s[slow++]);
                if (it2 == needs.end()) {
                    continue;
                } else if (it2->second++ >= 0) {
                    needCnt++;
                }
            } 
        }
        return res;
    }
};
