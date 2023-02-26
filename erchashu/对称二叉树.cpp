/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-17 20:33:23
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-17 21:33:34
 * @FilePath: /leet/erchashu/duichen.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
//检查一个二叉树是否镜像对称
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//利用栈的对对碰思想消除镜相元素,这种方法会超时
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return  false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            stack<int> st;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                if (!st.empty()||st.top() == node ->val) {
                    st.pop();
                }else {
                    st.push(node -> val);
                }
                q.pop();
                if (node ->left) q.push(node ->left);
                if (node -> right) q.push(node -> right);
            }
            if (!st.empty()) return false;
        }
        return true;
    }
};
// 迭代方法判断是否为对称
class Solution {
public:
    bool checkout(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        else if (root1 == nullptr && root2 != nullptr) return false;
        else if (root1 != nullptr && root2 == nullptr) return false;
        else if(root1 -> val != root2 -> val) return false;
        // 左右节点不为空，且数值相等，那么要向下一层进行递归了
        bool outside = checkout(root1 ->left, root2 -> right);
        bool inside = checkout(root1 -> right, root2 -> left);
        return outside&&inside;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return checkout(root->left,root->right);
    }
};
// 使用栈，但是不是层序遍历，发现不对就直接输出false
class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            stack<TreeNode*> st;
            if (root == nullptr) return true;
            st.push(root -> right);
            st.push(root -> left);
            while (!st.empty()) {
                TreeNode* left = st.top(); // 先取左
                st.pop();
                TreeNode* right = st.top(); //再取右
                st.pop();
                // 执行判断过程
                if (!left && !right) continue;
                if (!left || !right || left->val!=right->val) return false;
                // 输入下一层的值
                st.push(right -> right);  //右
                st.push(left -> left);    // 左
                st.push(right -> left);  // 右
                st.push(left -> right); //左
            }
            return true;
        }
};