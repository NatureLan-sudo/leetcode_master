#include "common_include.h"

// 二叉树的构造函数
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//144.给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
class Solution {
public:
    void qianxu(TreeNode* cur, vector<int>& ans) {//输入当前节点的指针，和要存储结果的vec
        if (cur == NULL) return;
        ans.push_back(cur -> val); // 存入中间节点
        qianxu(cur -> left, ans); //左边
        qianxu(cur -> right, ans); //右边
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        qianxu(root, ans);
        return ans;
    }
};
// 145.后序遍历 左右中
class Solution {
public:
    void houxu(TreeNode* cur, vector<int>& ans) {//输入当前节点的指针，和要存储结果的vec
        if (cur == NULL) return;
        houxu(cur -> left, ans);   // 左
        houxu(cur -> right, ans);  // 右
        ans.push_back(cur -> val);  // 中
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        houxu(root, ans);
        return ans;
    }
};
// 94.中序遍历
class Solution {
public:
    void midxu(TreeNode* cur, vector<int>& ans) {//输入当前节点的指针，和要存储结果的vec
        if (cur == NULL) return;
        midxu(cur -> left, ans);   // 左
        ans.push_back(cur -> val);  // 中
        midxu(cur -> right, ans);  // 右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        midxu(root, ans);
        return ans;
    }
};