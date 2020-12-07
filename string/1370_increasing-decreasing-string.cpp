/*
# 1370. 上升下降字符串
https://leetcode-cn.com/problems/increasing-decreasing-string/

给你一个字符串 s ，请你根据下面的算法重新构造字符串：
* 从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
* 从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
* 重复步骤 2 ，直到你没法从 s 中选择字符。
* 从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
* 从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
* 重复步骤 5 ，直到你没法从 s 中选择字符。
* 重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
* 在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。
请你返回将 s 中字符重新排序后的 结果字符串 。

    示例 1：
输入：s = "aaaabbbbcccc"
输出："abccbaabccba"
解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
    示例 2：
输入：s = "rat"
输出："art"
解释：单词 "rat" 在上述算法重排序以后变成 "art"
    示例 3：
输入：s = "leetcode"
输出："cdelotee"
    示例 4：
输入：s = "ggggggg"
输出："ggggggg"
    示例 5：
输入：s = "spo"
输出："ops"

    提示：
1 <= s.length <= 500
s 只包含小写英文字母。
 */

// 解法1: 桶排序
class Solution {
public:
    string sortString(string s) {
        // 特殊case: 长度为1或0, 返回输入本身即可(加速使用)
        if (s.length() < 2) {
            return s;
        }

        // 统计输入字符串中各个小写字符的出现次数
        int dict[26] = {0};
        for (auto &c : s) {
            dict[c-'a']++;
        }
        // 按照规则构造新字符串
        string res;
        while (res.size() < s.size()) {  // 直到原始字符串里所有字符用完
            // 正向遍历, 将当前剩余字符从小到大拼接到结果字符串
            for (int i = 0; i < 26; i++) {
                if (dict[i]) {
                    res.push_back('a'+i);
                    dict[i]--;
                }
            }
            // 反向遍历, 将当前剩余字符从大到小拼接到结果字符串
            for (int i = 25; i >= 0; i--) {
                if (dict[i]) {
                    res.push_back('a'+i);
                    dict[i]--;
                }
            }
        }
        return res;
    }
};