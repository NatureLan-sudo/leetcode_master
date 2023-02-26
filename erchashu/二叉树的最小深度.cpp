/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-19 09:31:47
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-19 10:41:31
 * @FilePath: /leet/erchashu/mindeep.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
// 最快到达叶子节点的节点数
// 叶子节点是左右孩都为空的情况
// 需要注意的是，只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 递归
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);        
        if (root -> left == nullptr && root ->right != nullptr) {  // 避免判断到一个小值，但是不是叶子节点就返回了
            return 1 +right;
        }
        if (root -> right == nullptr && root ->left != nullptr) {
            return 1+left;
        }
        int depth = 1 + min(left, right);
        return depth;
    }
};
// 层序
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i =0; i < size;i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node ->right)  q.push(node -> right);
                if (node -> left ==nullptr && node ->right == nullptr) return depth; // 如果这个节点的左右都为0 了那么就到叶子节点了，就直接输出深度
            }
        }
        return depth;
    }
};
