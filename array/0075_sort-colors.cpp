/*
# 75. 颜色分类
https://leetcode-cn.com/problems/sort-colors/

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

    注意:
不能使用代码库中的排序函数来解决这道题。

    示例:
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
    进阶：
一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？
 */

// 解法1: 计数排序 + 两趟扫描
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Step1: 分别统计三种颜色出现的次数
        std::vector<int> clac(3);
        for (auto it = nums.begin(); it != nums.end(); it++) {
            clac[*it]++;
        }
        // Step2: 根据统计结果重新对原始数组置位
        int k = 0;
        for (int i = 0; i < clac.size(); i++) {
            for (int j = 0; j < clac[i]; j++) {
                nums[k++] = i;
            }
        }
    }
};

// 解法2: 利用快速排序的partition
// 参考: https://leetcode-cn.com/problems/sort-colors/solution/c-chao-100-he-lan-guo-qi-wen-ti-by-the-wall-2/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        int i = 0;
        while (i <= p2) {
            if (nums[i] < 1) {
                // 将0换到P0区域尾部, P0区域扩大(因为p0 <= i, 而[0,i]区间内
                // 所有元素已经遍历过, 能保证新的nums[i] <= 1, 所以直接i++)
                swap(nums, i++, p0++);
            } else if (nums[i] > 1) {
                // 将2换到P2区域头部, P2区域扩大(因为p2 >= i, [i+1,p2]区间
                // 内的元素还未遍历过, 不能保证新的nums[i] >= 1, 不能i++)
                swap(nums, i, p2--);
            } else {
                i++;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        if (i == j) return;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp; 
    }
};

