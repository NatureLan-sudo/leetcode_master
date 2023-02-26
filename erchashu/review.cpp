/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-17 20:05:15
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-17 20:32:40
 * @FilePath: /leet/erchashu/review.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
 class TreeNode {
   public:
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
 };
 // 深度迭代统一,以前序为例
 class Solution {
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node ->right) st.push(node ->right);  //右
                if (node -> left) st.push(node -> left); // 左
                st.push(node);  // 中
                st.push(nullptr);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node -> val);
            }
        }
        return res;
    }
};
// 层次迭代
class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                vec.push_back(node -> val);
                q.pop();
                if (node ->left) q.push(node -> left);
                if (node ->right) q.push(node -> right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
