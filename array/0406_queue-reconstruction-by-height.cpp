/*
# 406. 根据身高重建队列
https://leetcode-cn.com/problems/queue-reconstruction-by-height/

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
    注意：
总人数少于1100人。

    示例
输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

// 解法1: 先排序后插入
bool cmp(std::vector<int>& a, std::vector<int>& b) {
    // 优先按照高度h降序排列
    if (a[0] > b[0]) {
        return true;
    }
    // 高度相同按照人数k升序排列
    return a[0] == b[0] && a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序: 优先按照高度h降序排列, 高度相同按照人数k升序排列
        std::sort(people.begin(), people.end(), cmp);

        // 遍历排序好的队列, 按照每个人的k值依次插入新队列
        std::list<vector<int>> tmp;  // 缓存重排结果的新队列
        for (auto &p : people) {
            auto pos = tmp.begin();
            std::advance(pos, p[1]);  // 根据其k值定位到其在新队列中的位置
            tmp.insert(pos, p);
        }
        // 将list类型的临时队列转存为vector类型的结果队列
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
