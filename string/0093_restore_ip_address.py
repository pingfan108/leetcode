"""
93. 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

    示例:
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
"""

# 解法1: 暴力美学解法
# 参考, https://leetcode-cn.com/problems/restore-ip-addresses/solution/ke-neng-shi-zui-you-mei-de-bao-li-jie-fa-liao-by-u/
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = [];
        for len1 in xrange(1, 4):
            for len2 in xrange(1, 4):
                for len3 in xrange(1, 4):
                    # Step1: 由前三个子串的长度推导第四个子串的长度len4
                    len4 = len(s) - len1 - len2 - len3;
                    if len4 < 1 or len4 > 3:
                        # 筛除第四个子串长度不合法的情况
                        continue;

                    # Step1: 将4个子串分别转成数字
                    n1 = int(s[:len1]);
                    n2 = int(s[len1:(len1+len2)]);
                    n3 = int(s[(len1+len2):(len1+len2+len3)]);
                    n4 = int(s[(len1+len2+len3):]);
                    if n1 > 255 or n2 > 255 or n3 > 255 or n4 > 255:
                        # 筛除这4个数字超出[0,255]区间的情况
                        continue;

                    # Step3: 将4个数字转回点分十进制的标准IP地址格式
                    nums = [str(n1), str(n2), str(n3), str(n4)];
                    ip = '.'.join(nums);
                    if len(ip) != len(s) + 3:
                        # 筛除子串中存在以'0'开头的情况
                        continue;

                    # Step4: 记录合法的IP地址
                    res.append(ip);
        return res;
