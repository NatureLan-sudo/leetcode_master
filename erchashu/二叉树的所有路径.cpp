#include "common_include.h"
// 给你一个二叉树的根节点 root ，按任意顺序 ，返回所有从根节点到叶子节点的路径
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        string path;
        func(root, res, path);
        return res;
    }
    void func(TreeNode* node, vector<string>& res, string path) {
        path += to_string(node -> val);
        if (node -> left) func(node -> left, res, path + "->");
        if (node -> right) func(node -> right, res, path + "->");
        if (node ->right == nullptr && node -> left == nullptr) {
            res.push_back(path);
            return;
        }
    }

};