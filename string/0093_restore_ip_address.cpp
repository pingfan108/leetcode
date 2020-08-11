/*
# 93. 复原IP地址
https://leetcode-cn.com/problems/restore-ip-addresses/

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

    示例:
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
 */

// 解法1: 暴力美学三重奏
// 思路:
// * 组成有效IP地址的四个子字符串长度只能是在[1,3]之间. 暴力尝试所有可能的长度,
//   再将其中无效的组合(结果长度和原始字符串长度不匹配, 超出255范围等)筛掉即可.
// * 虽然是三重循环(原题解中是四重循环), 但循环次数恒定, 时间复杂度为O(1).
// * 参考, https://leetcode-cn.com/problems/restore-ip-addresses/solution/ke-neng-shi-zui-you-mei-de-bao-li-jie-fa-liao-by-u/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<std::string> res;
        for (int len1 = 1; len1 < 4; len1++) {
            for (int len2 = 1; len2 < 4; len2++) {
                for (int len3 = 1; len3 < 4; len3++) {
                    // Step1: 由前三个子串的长度推导第四个子串的长度len4
                    int len4 = s.length() - len1 - len2 - len3;
                    if (len4 < 1 || len4 > 3) {
                        // 筛除第四个子串长度不合法的情况
                        continue;
                    }

                    // Step2: 将4个子串分别转成数字
                    int n1 = atoi(s.substr(0, len1).c_str());
                    int n2 = atoi(s.substr(len1, len2).c_str());
                    int n3 = atoi(s.substr(len1+len2, len3).c_str());
                    int n4 = atoi(s.substr(len1+len2+len3, len4).c_str());
                    if (n1 > 255 || n2 > 255 || n3 > 255 || n4 > 255) {
                        // 筛除这4个数字超出[0,255]区间的情况
                        continue;
                    }

                    // Step3: 将4个数字转回点分十进制的标准IP地址格式
                    std::ostringstream oss;
                    oss << n1 << "." << n2 << "." << n3 << "." << n4;
                    std::string ip = oss.str();
                    if (ip.length() != s.length() + 3) {
                        // 筛除子串中存在以'0'开头的情况
                        continue;
                    }

                    // Step4: 记录合法的IP地址
                    res.push_back(ip);
                }
            }
        }
        return res;
    }
};
