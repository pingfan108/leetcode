/*
# 239. 滑动窗口最大值
https://leetcode-cn.com/problems/sliding-window-maximum/

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。

    示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
    示例 2：
输入：nums = [1], k = 1
输出：[1]
    示例 3：
输入：nums = [1,-1], k = 1
输出：[1,-1]
    示例 4：
输入：nums = [9,11], k = 2
输出：[11]
    示例 5：
输入：nums = [4,-2], k = 2
输出：[4]

    提示：
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
 */

// 解法1: 滑动窗口+multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        //// 特殊case: 输入参数不合法(按照题意可省略)
        if (nums.size() < k) {
            return res;
        }

        //// 一般case: 滑动窗口+multiset(可重复且有序)
        std::multiset<int> numSet;  // 记录当前窗口访问内的元素并排序
        for (int i = 0; i < nums.size(); i++) {
            // 扩展窗口右边界, 将边界新元素纳入
            numSet.insert(nums[i]);
            // 收缩窗口左边界, 将边界老元素移出(当窗口大小超出限制k)
            if (numSet.size() > k) {
                // !!!Note!!! 此处要注意, multiset的erase()如果直接传val,
                // 会把numSet中所有值为val的元素都删掉, 不符合我们的预期;
                // 正确的做法是: 通过find()返回其中一个具体元素的iterator,
                // 作为参数传递给erase(), 表明只想删掉这个指定的元素.
                numSet.erase(numSet.find(nums[i-k]));
            }
            // 将当前合法窗口内的最大值记录到结果数组
            if (numSet.size() == k) {
                res.push_back(*numSet.rbegin());
            }
        }
        return res;
    }
};


// 解法2: 滑动窗口+单调队列(参考《剑指offer》)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        //// 特殊case: 输入参数不合法(按照题意可省略)
        if (nums.size() < k) {
            return res;
        }

        //// 一般case: 滑动窗口+单调队列(通过出队入队维护单调性)
        std::deque<int> helpQueue;  // 单调队列, 头大尾小
        for (int i = 0; i < nums.size(); i++) {
            // 扩展窗口右边界, 将边界新元素纳入
            while (!helpQueue.empty() && nums[i] > helpQueue.back()) {
                // 将helpQueue所有小于nums[i]的元素移除, 避免破坏单调性
                // Note: 与nums[i]相等的元素不用移除, 等待左边界收缩时处理
                helpQueue.pop_back();
            }
            helpQueue.push_back(nums[i]);

            // 收缩窗口左边界, 将边界老元素移出(当窗口大小超出限制k)
            if (i >= k && nums[i-k] == helpQueue.front()) {
                // 若nums[i-k]刚好是当前的最大元素, 则需将其从单调队列中移除;
                // 否则在当前最大元素当初入队的时候, nums[i-k]已因保持单调性
                // 的需要而被移除.
                helpQueue.pop_front();
            }

            // 将当前合法窗口内的最大值记录到结果数组
            if (i >= k-1) {
                res.push_back(helpQueue.front());
            }
        }
        return res;
    }
};

