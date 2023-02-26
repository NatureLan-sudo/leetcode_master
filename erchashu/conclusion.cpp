/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-14 09:53:26
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-14 10:52:50
 * @FilePath: /leet/erchashu/conclusion.cpp
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
 // 深度递归
 class Solution {
    public:
    vector<int> qianxufuzhu(TreeNode* node, vector<int>& vec) {
        if (node == nullptr) return;
        vec.push_back(node -> val); // 中
        if (node -> left) qianxufuzhu(node->left,vec); // 左
        if (node -> right) qianxufuzhu(node -> right, vec); // 右
        // 中序
        // if(node == nullptr) return;
        // if (node -> left) zhongxufuzhu(node -> left, vec);
        // vec.push_back(node -> val);
        // if (node -> right) zhongxufuzhu(node -> right, vec);
        // 后序
        // if(node == nullptr) return;
        // if (node -> left) houxufuzhu(node -> left, vec);
        // if (node -> right) houxufuzhu(node -> right, vec);
        // vec.push_back(node -> val);
    }
    vector<int> qianxu(TreeNode* root) {
        vector<int> res;
        qianxufuzhu(root, res);
        return res;
    }
 };
 //*********
 // 深度迭代
 // 利用栈实现递归的过程
 // 前序
 class Solution{
    public:
    vector<int> qianxu(TreeNode* root) {// 中左右
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node -> val);
            if (node -> right) st.push(node -> right); //右
            if (node -> left) st.push(node -> left);   // 左 后入先出
        }
        return res;
    }
 };
// 后序，在前序基础上改动  中左右  左右中  中右左
class Solution{
    public:
    vector<int> houxu(TreeNode* root) {// 中左右
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node -> val); //中
            if (node -> left) st.push(node -> left);   // 左 后入先出
            if (node -> right) st.push(node -> right); //右
        }
        reverse(res.begin(),res.end());
        return res;
    }
 };
//中序，由于中间节点的位置发生改变，所以中序需要重写
class Solution{
    public:
    vector<int> zhongxu(TreeNode* root) {// 中左右
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur = root;
        while (cur != nullptr ||!st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur -> left; // 找到最后一个左节点 
            } else {
                // 说明找到左节点的最底层了
                cur = st.top();
                st.pop();
                res.push_back(cur -> val);// 中
                cur = cur ->right;    // 右
            }
        }
        return res;
    }
 };

//********
//***
//统一格式深度迭代，利用标记法
// 前序
class Solution {
    public:
    vector<int> qianxu(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node -> right) st.push(node -> right); // 右
                if (node -> left) st.push(node -> left); // 左
                st.push(node);     // 中
                st.push(nullptr);   // 标记
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
// 中序
class Solution {
    public:
    vector<int> zhongxu(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node -> right) st.push(node -> right); // 右
                st.push(node);     // 中
                st.push(nullptr);   // 标记
                if (node -> left) st.push(node -> left); // 左
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
//后序
class Solution {
    public:
    vector<int> houxu(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                st.push(node);     // 中
                st.push(nullptr);   // 标记
                if (node -> right) st.push(node -> right); // 右
                if (node -> left) st.push(node -> left); // 左
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
//*****
//层次迭代
// 层次迭代利用队列实现，先进的先出去
class Solution {
    public:
    vector<vector<int>> cengci(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node -> val);
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
//***
//**翻转
//通过深度或者广度都可以，只需要把输出值的地方改成交换节点的左右孩就可以
