/*
# 763. 划分字母区间
https://leetcode-cn.com/problems/partition-labels/

字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

    示例 1：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

    提示：
S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。
 */

// 解法1: 哈希表 + 贪心算法 + 双指针
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // 反向遍历S, 记录S中每个字符最后出现的位置
        std::vector<int> last(26, -1);
        int i = S.length() - 1;
        for (; i >= 0; i--) {
            if (last[S[i] - 'a'] < 0) {
                last[S[i] - 'a'] = i;
            }
        }

        // 正向遍历S, 用贪心算法+双指针
        std::vector<int> res;
        int fast = 0, slow = 0;  // 快慢指针
        // 外层循环的每一轮, 对应一个片段
        while (fast < S.length()) {
            slow = fast;  // 将慢指针移到当前片段第一个字母的位置
            int end = last[S[fast] - 'a'];  // 设定当前片段的最小边界
            // 内层循环遍历当前片段的每一个字符
            while (fast <= end) {
                // 在不可避免的情况下(当前字符的最后出现位置超出当前片段的范围,
                // 破坏条件"同一个字母只会出现在其中的一个片段"), 扩大当前片段
                end = std::max(end, last[S[fast] - 'a']);
                fast++;
            }
            // 当前片段遍历完毕, 所有字符都只在次片段内, 记录当前片段长度
            res.push_back(fast - slow);
        }
        return res;
    }
};
