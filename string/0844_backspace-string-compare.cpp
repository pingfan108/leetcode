/*
# 844. 比较含退格的字符串
https://leetcode-cn.com/problems/backspace-string-compare/

给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

    示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
    示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
    示例 3：
输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
    示例 4：
输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。

    提示：
1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。

    进阶：
你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 */

// 解法1: 基于栈重构字符串(去掉退格符)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // 直接比较原始字符串消掉'#'的新字符串是否相等
        return rebuildString(S) == rebuildString(T);
    }

    // 基于栈消掉原始字符串中的'#', 生成不带'#'的新字符串
    std::string rebuildString(string instr) {
        std::string res;
        for (int i = 0; i < instr.length(); i++) {
            if (instr[i] != '#') {
                // 合法字符入栈
                res.push_back(instr[i]);
            } else if (res.length()) {
                // 栈非空的情况下将'#'前面的字符出栈
                res.pop_back();
            }
        }
        return res;  // 返回不带'#'的新字符串
    }
};

// 解法2: 双指针
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // 用双指针分别逆序遍历S和T, 看相应位置是否匹配
        int i = S.length() - 1;
        int j = T.length() - 1;
        while (i >= 0 || j >= 0) {
            // 从i开始往前, 找到S中第一个不被抵消的非'#'字符
            int skip = 0;
            while (i >= 0) {
                if (S[i] == '#') {
                    skip++;
                } else if (skip) {
                    skip--;
                } else {
                    break;  // S[i] != '#' && skip == 0
                }
                i--;
            }
            // 从j开始往前, 找到T中第一个不被抵消的非'#'字符
            skip = 0;
            while (j >= 0) {
                if (T[j] == '#') {
                    skip++;
                } else if (skip) {
                    skip--;
                } else {
                    break;  // T[j] != '#' && skip == 0
                }
                j--;
            }

            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    // 找到第一对不匹配的字符, 直接返回
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    // 其中一个已遍历完, 另一个还有不能抵消的部分, 不匹配
                    return false;
                }
            }
            i--;
            j--;
        }
        return true;
    }
};
