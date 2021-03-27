/*
# 697. 数组的度
https://leetcode-cn.com/problems/degree-of-an-array/

给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

    示例 1：
输入：[1, 2, 2, 3, 1]
输出：2
解释：
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
    示例 2：
输入：[1,2,2,3,1,4,2]
输出：6

    提示：
nums.length 在1到 50,000 区间范围内。
nums[i] 是一个在 0 到 49,999 范围内的整数。
 */

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // num => [cnt, beg, end]
        std::unordered_map<int, std::vector<int> > cntMap;
        // 遍历nums数组, 统计每个元素 出现的次数 && 首次出现索引 && 最后出现索引
        for (int i = 0; i < nums.size(); i++) {
            auto iter = cntMap.find(nums[i]);
            if (iter == cntMap.end()) {
                // 首次出现的元素, cnt=1, beg=end=i
                std::vector<int> tmp = {1, i, i};
                cntMap[nums[i]] = std::move(tmp);
            } else {
                // 重复出现的元素, 只需更新cnt和end
                iter->second[0]++;
                iter->second[2] = i;
            }
        }
        // 遍历统计结果, 找到cnt最大且长度最小的元素
        int maxCnt = 0, minLen = 0;
        for (auto iter = cntMap.begin(); iter != cntMap.end(); iter++) {
            if (iter->second[0] > maxCnt) {
                maxCnt = iter->second[0];
                minLen = iter->second[2] - iter->second[1] + 1;
            } else if (iter->second[0] == maxCnt) {
                minLen = std::min(minLen, iter->second[2] - iter->second[1] + 1);
            }
        }
        return minLen;
    }
};
