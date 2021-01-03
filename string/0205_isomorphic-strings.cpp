/*
#205. 同构字符串
https://leetcode-cn.com/problems/isomorphic-strings/

给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。 

    示例 1:
输入：s = "egg", t = "add"
输出：true
    示例 2：
输入：s = "foo", t = "bar"
输出：false
    示例 3：
输入：s = "paper", t = "title"
输出：true

    提示：
可以假设 s 和 t 长度相同。
 */

// 解法1: 哈希表
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, char> dict;  // 记录s到t的映射关系
        std::unordered_set<char> tset;        // 记录t中已被映射的字符集合
        for (int i = 0; i < s.length(); i++) {
            auto it = dict.find(s[i]);
            if (it == dict.end()) {
                if (tset.find(t[i]) != tset.end()) {
                    return false;  // 不同的字符映射到了同一个字符
                }
                dict[s[i]] = t[i];
                tset.insert(t[i]);
            } else if (it->second != t[i]) {
                return false;  // 同一个字符映射到了不同的字符
            }
        }
        return true;
    }
};
