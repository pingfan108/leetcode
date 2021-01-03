/*
# 454. 四数相加 II
https://leetcode-cn.com/problems/4sum-ii/

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

    例如:
输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:
2
解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

// 解法1: 哈希表
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // 将AB的和转为哈希表: sum -> count
        std::unordered_map<int, int> dict;
        for (int a : A) {
            for (int b : B) {
                dict[a+b]++;
            }
        }

        int res = 0;
        // 双重循环遍历C,D, 根据c+d的相反数查询哈希表, 看是否有-(c+d)存在
        for (int c : C) {
            for (int d : D) {
                auto it = dict.find(0 - c - d);
                if (it != dict.end()) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};

// 解法1.1: 哈希表(有测试用例超时)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // 将D转为哈希表: elem -> count
        std::unordered_map<int, int> dict;
        for (int i = 0; i < D.size(); i++) {
            dict[D[i]]++;
        }

        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                for (int k = 0; k < C.size(); k++) {
                    auto it = dict.find(0 - A[i] - B[j] - C[k]);
                    if (it != dict.end()) {
                        res += it->second;
                    }
                }
            }
        }
        return res;
    }
};
