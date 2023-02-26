/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-14 09:02:30
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-14 09:42:42
 * @FilePath: /leet/erchashu/reverse.cpp
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
// 交换每一个子节点
// 深度  栈
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        //vector<int> res;
        if (root == nullptr) return root;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
                st.push(node);
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                //res.push_back(node -> val);
                swap(node -> left, node->right); // 相当于对于遍历来说值更改了这一个地方
            }
        }

    }
};
// 广度  队列
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        //vector< vector<int> > res;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            //vector<int> vec;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                //vec.push_back(node -> val);
                if (node ->left) q.push(node->left);
                if (node -> right) q.push(node -> right);
                swap (node -> left, node -> right);
            }
            //res.push_back(vec);
        }
        return root;
    }
};