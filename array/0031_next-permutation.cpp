/*
# 31. 下一个排列
https://leetcode-cn.com/problems/next-permutation/

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
 */

// 解法1: 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 特殊case: 只有一种排列的情况
        if (nums.size() < 2) {
            return;
        }

        // 从后往前, 找到第一个升序排列的相邻元素对: i,i-1
        int i = nums.size() - 1;
        for (; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                // 找到最后一个相邻的升序元素对后, 从i-1后面的元素中找比i-1大的
                // 最小元素j(一定存在, 最差情况是j=i), 将i-1和j交换
                for (int j = nums.size() - 1; j >= i; j--) {
                    if (nums[j] > nums[i-1]) {
                        swap(nums, j, i-1);
                        break;
                    }
                }
                break;
            }
        }
        // 此时有两种可能:
        // 1. 在原始序列中找到了一个升序排列的相邻元素对, 并进行了交换; i-1之后
        //    的子序列[i,size-1]当前为降序序列, 需逆置为升序序列;
        // 2. 在原始序列中没有找到升序排列的相邻元素对, 直到i==0退出循环(等价于
        //    说原始序列为最大排列, 即降序排列), 此时应该返回最小排列, 即将整个
        //    原始序列[0,size-1]逆置为升序排列;
        // 无论是哪种情况, 需要做的都是将[i,size-1]逆置, 逻辑可以统一
        int j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    } 
};
