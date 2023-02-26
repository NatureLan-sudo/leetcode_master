/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-17 21:36:09
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-19 19:46:39
 * @FilePath: /leet/erchashu/deep.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */

#include "common_include.h"
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 使用层序就是模板了
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        if (root == nullptr) return 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            depth++;

        }
        return depth;
    }
};
// 递归 
class Solution {
public:
    int getdepth(TreeNode* root) {
        if (root == nullptr) return 0; // 终止条件
        // 单层迭代逻辑
        int left = getdepth(root -> left);
        int right = getdepth(root -> right);
        // 返回值
        int depth = 1 + max (left,right);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};