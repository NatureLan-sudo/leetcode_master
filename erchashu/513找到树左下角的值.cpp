#include "common_include.h"
// 找到二叉树最后一行最左边的节点的值
// 层序遍历，存储第一个值
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) return 0;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            res = node->val;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                if (node ->left) q.push(node -> left);
                if (node -> right) q.push(node ->right);
            }
        }
        return res;
    }
};