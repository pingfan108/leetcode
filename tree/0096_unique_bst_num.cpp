/*
# 96. 不同的二叉搜索树
https://leetcode-cn.com/problems/unique-binary-search-trees/

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

	示例:
输入: 3
输出: 5
解释: 给定 n = 3, 一共有如下 5 种不同结构的二叉搜索树:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include "include/tree.h"

// 解法1: 动态规划
// 思路:
// * 按照BST的定义，若[1,n]区间中的整数k作为根节点，则[1,k-1]区间会去构建左子树,
//   [k+1,n]区间会去构建右子树;
// * 以k为根节点的 BST种类数 = 左子树BST种类数 * 右子树BST种类数;
// * 问题变成：计算不同的k之下，等式右边的种类数的累加结果.
// * BST的种类数仅和有序序列的长度相关, 跟序列具体取值无关!
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;

        //// Step1: 创建并初始化状态转移数组
        ////        dp[i]表示由长度为i的有序序列组成的BST种类数
        int dp[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = 1;  // 空二叉树
        dp[1] = 1;  // 只有根节点的二叉树
        //// Step2: 依次填充状态转移数组
        for (int i = 2; i <= n; i++) {       // i表示有序序列总长度
            for (int j = 0; j < i; j++) {    // j表示组成左子树的有序子序列长度
                // 固定BST根节点为j+1, 右子树节点数为i-1-j
                dp[i] += dp[j] * dp[i-1-j];  // 左子树种类数 * 右子树种类数
            }
        }
        //// Step3: dp[n]即为题解
        return dp[n];
    }
};

// 解法2: 经折半优化的动态规划
// 思路:
// * 基于二叉树左右子树的可交换性, 后一半的结果与前一半成镜像对称; 对于状态转移
//   过程中的每一个dp[i], 只需算左子树节点数少于一半的情况, 最后乘2即可.
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;

        //// Step1: 创建并初始化状态转移数组
        ////        dp[i]表示由长度为i的有序序列组成的BST种类数
        int dp[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = 1;  // 空二叉树
        dp[1] = 1;  // 只有根节点的二叉树
        //// Step2: 依次填充状态转移数组
        for (int i = 2; i <= n; i++) {       // i表示有序序列长度
            int mid = i >> 1;
            for (int j = 0; j < mid; j++) {  // j表示组成左子树的有序子序列长度
                // 固定BST根节点为j+1, 右子树节点数为i-1-j
                dp[i] += dp[j] * dp[i-1-j] * 2;  // 左子树种类数*右子树种类数*2
            }
            // 当i为奇数时, 需补上左右子序列长度相等的情况
            if (i&1) {
                dp[i] += dp[mid] * dp[mid];
            }
        }
        // Step3: dp[n]即为题解
        return dp[n];
    }
};
