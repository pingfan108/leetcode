/*
# 922. 按奇偶排序数组 II
https://leetcode-cn.com/problems/sort-array-by-parity-ii/

给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
你可以返回任何满足上述条件的数组作为答案。

    示例：
输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。

    提示：
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
 */

// 解法: 双指针
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0;
        int j = 1;
        while (i < A.size() - 1 && j < A.size()) {
            while (i < A.size() - 1 && A[i] % 2 == 0) {
                i += 2;
            }
            while (j < A.size() && A[j] % 2 == 1) {
                j += 2;
            }
            if (i >= A.size() - 1 || j >= A.size()) {
                break;
            }
            swap(A, i, j);
            i += 2;
            j += 2;
        }
        return A;
    }

    void swap(vector<int>& A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
};
