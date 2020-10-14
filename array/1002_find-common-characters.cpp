/*
# 1002. 查找共用字符
https://leetcode-cn.com/problems/find-common-characters/

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
你可以按任意顺序返回答案。 

    示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]
    示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]

    提示：
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母
 */

// 解法1: 哈希表计数填充
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        //// Step1: 统计A中各字符出现的最小次数
        int dict[26] = {0};  // 哈希计数器
        // Step1.1: 用第1个字符串中各字符出现的次数初始化哈希计数器
        for (int j = 0; j < A[0].length(); j++) {
            dict[A[0][j] - 'a']++;
        }
        // Step1.2: 遍历A中剩余的字符串, 更新哈希计数器
        for (int i = 1; i < A.size(); i++) {
            // 统计A[i]中各字符出现的次数
            int tmpDict[26] = {0};
            for (int j = 0; j < A[i].length(); j++) {
                tmpDict[A[i][j] - 'a']++;
            }
            // 用更小的出现次数更新哈希计数器
            for (int k = 0; k < 26; k++) {
                dict[k] = std::min(dict[k], tmpDict[k]);
            }
        }

        //// Step2: 根据哈希计数器的结果填充结果数组
        std::vector<std::string> res;  // 结果数组
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            for (int j = 0; j < dict[i]; j++) {
                res.push_back(std::string(1, c));
            }
        }
        return res;
    }
};
