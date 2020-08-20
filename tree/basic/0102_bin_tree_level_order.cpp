/*
# 102. 二叉树的层序遍历
https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。例如,
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]

    提示：
节点总数 <= 1000
 */

// 解法1: BFS(标记层次)
// 思路:
// * 基于队列的朴素BFS可完成层序遍历, 但遍历结果是一个一维数组，无法区分每一层,
//   原因是队列中只存放了二叉树的节点指针;
// * 一个简单的想法是扩展队列元素的结构, 在元素中附带节点的层次信息, 这样每遍历
//   一个节点的时候, 就能很容易知道应该插入哪个结果数组中;
// * 每次需要将当前节点的子节点插入队列的时候, 其层数为当前节点的层数+1.
struct Elem {
    int level;       // 层数(从1开始)
    TreeNode* node;  // 原始的二叉树节点
    Elem(int x, TreeNode* n) : level(x), node(n) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > res;
        // 创建一个队列来存放遍历过程中已处理节点的子节点
        std::queue<Elem> elems;
        // 根节点入队(初始化为1是为了便于结果数组的插入处理)
        Elem elem(1, root);
        elems.push(elem);
        // 队列元素依次出队, 直至队列为空
        while (!elems.empty()) {
            auto elem = elems.front();
            if (elem.node != NULL) {
                if (elem.level > res.size()) {
                    // 已经遍历到下一层, 需要新建一个空数组
                    res.push_back(std::vector<int>());
                }
                // 将当前节点的值插入结果数组中最后一行末尾
                res[elem.level - 1].push_back(elem.node->val);
                // 将当前节点的左右子节点插入队列
                elems.push(Elem(elem.level + 1, elem.node->left));
                elems.push(Elem(elem.level + 1, elem.node->right));
            }
            // 当前节点处理完毕, 可以出队
            elems.pop();
        }
        return res;
    }
};

// 解法2: BFS(计算层次)
// 思路:
// * 使用双层循环, 内层循环负责当前层次所有节点, 外层循环负责二叉树所有的层;
// * 外层循环每次进入的时候, 队列当前的长度即为二叉树当前层次的节点数(设为N),
//   将内层循环的循环次数设为N, 即可保证每轮内层循环结束后当前层次遍历完毕.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > res;
        // 特殊case: 空二叉树
        if (root == NULL) {
            return res;
        }

        std::queue<TreeNode*> nodes;  // 保存已处理节点的子节点
        nodes.push(root);             // 根节点入队
        while (!nodes.empty()) {
            // Step1: 获取当前层次的节点数
            int n = nodes.size();
            // Step2: 创建存放当前层次遍历结果的临时数组
            std::vector<int> tmp;
            // Step3: 完成当前层次的遍历(遍历队列的前n个节点)
            for (int i = 0; i < n; i++) {
                // 保存当前队首节点的值
                auto node = nodes.front();
                tmp.push_back(node->val);
                // 将当前队首节点的左右子节点插入队列末尾
                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
                // 当前队首节点处理完毕, 可以出队
                nodes.pop();
            }
            // Step4: 将当前层次的遍历结果插入最终结果末尾
            res.push_back(tmp);
        }
        return res;
    }
};
