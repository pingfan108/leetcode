/*
# 841. 钥匙和房间
https://leetcode-cn.com/problems/keys-and-rooms/

有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。
* 在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i];
* 每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。
* 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
最初，除 0 号房间外的其余所有房间都被锁住。
你可以自由地在房间之间来回走动。
如果能进入每个房间返回 true，否则返回 false。

    示例 1：
输入: [[1],[2],[3],[]]
输出: true
解释:
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。

    示例 2：
输入：[[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。

    提示：
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
所有房间中的钥匙数量总计不超过 3000。
 */

// 解法1: DFS
// 思路:
// * 使用深度优先搜索的方式尝试访问所有房间, 统计可以到达的房间个数;
// * 增加一个额外的数组来记录当前房间是否已经访问过, 防止重复访问;
// * 搜索结束后检查可以到达的房间个数是否等于房间总数即可.
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // 记录房间总数
        int todo = rooms.size();
        // 一个额外的状态数组, done[i]表示房间i是否已经访问过
        std::vector<bool> done(todo, false);
        // 基于深度优先策略, 尝试遍历所有能到达的房间
        dfs(rooms, 0, done, todo);
        // 检查是否还有房间未访问
        return todo == 0;
    }

    // 基于深度优先策略, 尝试遍历所有能到达的房间
    // rooms, 房间和钥匙的对应关系
    // i,     当前正在访问的房间编号
    // done,  标记房间是否访问过的状态数组
    // todo,  统计未访问房间的计数器
    void dfs(vector<vector<int>>& rooms, int i, vector<bool>& done, int& todo) {
        done[i] = true;  // 标记当前房间已访问
        todo--;          // 未访问房间计数减一
        if (todo == 0) {
            return;      // 所有房间已访问, 直接返回即可
        }

        // 依次取出当前房间里的所有钥匙, 
        for (auto &key : rooms[i]) {
            if (done[key]) {
                continue;  // 当前房间已访问, 不用重复搜索
            }
            dfs(rooms, key, done, todo);  // 递归搜索下一个房间
            if (todo == 0) {
                return;    // 所有房间已访问, 直接返回即可
            }
        }
    }
};
