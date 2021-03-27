/*
# 1122. 数组的相对排序
https://leetcode-cn.com/problems/relative-sort-array/

给你两个数组，arr1 和 arr2，
  * arr2 中的元素各不相同
  * arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

    示例：
输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]

    提示：
arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中
 */

// 解法1: 哈希表 + 计数排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step1: 遍历arr2, 将arr2中元素转存为哈希表
        std::unordered_map<int, int> count;
        for (auto &num : arr2) {
            count[num] = 0;
        }
        // Step2: 遍历arr1, 如果元素在arr2中存在, 统计其出现次数; 反之, 将其存到more数组
        std::vector<int> more;
        for (auto &num : arr1) {
            auto it = count.find(num);
            if (it == count.end()) {
                more.push_back(num);
            } else {
                it->second++;
            }
        }
        // Step3: 遍历arr2, 根据元素num的统计结果N, 依次填充N个num到arr1中
        int i = 0;
        for (auto &num : arr2) {
            int cnt = count[num];
            while (cnt--) {
                arr1[i++] = num; 
            }
        }
        // Step4: 对more数组排序, 然后将more数组中的元素依次填充arr1的后半部分
        std::sort(more.begin(), more.end());
        for (int j = 0; j < more.size(); j++) {
            arr1[i++] = more[j];
        }
        return arr1;
    }
};

// 解法2: 计数排序

