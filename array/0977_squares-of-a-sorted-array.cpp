/*
# 977. 有序数组的平方
https://leetcode-cn.com/problems/squares-of-a-sorted-array/

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

    示例 1：
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
    示例 2：
输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]

    提示：
1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。
 */

// 解法1: 找突变点切割后归并排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::vector<int> res(A.size());
        // 将A中每个数字转为其平方, 顺带找到平方值的单调突变点
        int mid = -1;
        for (int i = 0; i < A.size(); i++) {
            if (mid < 0 && A[i] >= 0) {
                mid = i;  // 找到第一个非负数的下标
            }
            A[i] = A[i] * A[i];
        }
        if (mid < 0) {
            mid = 0;
        }

        // 以突变点做切割将新的A切为两个子数组, 对两个子数组做归并排序
        int l = mid - 1;
        int r = mid;
        int i = 0;
        while (l >= 0 || r < A.size()) {
            if (l < 0) {
                res[i++] = A[r++];
            } else if (r >= A.size()) {
                res[i++] = A[l--];
            } else if (A[l] <= A[r]) {
                res[i++] = A[l--];
            } else {
                res[i++] = A[r++];
            }
        }
        return res;
    }
};
