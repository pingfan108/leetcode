/*
# 389. 找不同
https://leetcode-cn.com/problems/find-the-difference/

给定两个字符串 s 和 t，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。

    示例 1：
输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
    示例 2：
输入：s = "", t = "y"
输出："y"
    示例 3：
输入：s = "a", t = "aa"
输出："a"
    示例 4：
输入：s = "ae", t = "aea"
输出："a"

    提示：
0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母
 */

// 解法1: 哈希表
class Solution {
public:
    char findTheDifference(string s, string t) {
        // 初始化字符计数器
        int count[26] = {0};
        // 遍历字符串s, 统计s中每个字符的出现次数
        for (char &c : s) {
            count[c - 'a']++;
        }
        char res;
        // 遍历字符串t, 每出现一个字符就将相应计数器-1
        for (char &c : t) {
            if (count[c - 'a']) {
                count[c - 'a']--;
            } else {
                // c的计数器已经为0, 还有c出现, 一定是多出来的
                res = c;
                break;
            }
        }
        return res;
    }
};

// 解法2: 位运算
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        // 遍历字符串s, 每个字符逐个与res做异或
        for (char &c : s) {
            res ^= c;
        }
        // 遍历字符串t, 每个字符逐个与res做异或
        for (char &c : t) {
            res ^= c;  // 所有和之前s中相同的字符都会被消掉
        }
        // 两轮异或操作之后, 剩下的就是添加的字符
        return res;
    }
};
