/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-14 08:43:15
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-14 08:57:31
 * @FilePath: /leet/erchashu/cengci.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
// 采用层次遍历的方法，输出每一层的vector,将每一层再打包成vector
#include "common_include.h"
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(nullptr), right(nullptr) {};
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;  // 用于存储节点
        vector< vector<int> > res;  // 用于存储结果
        if (root == nullptr) return res;
        q.push(root);
        while (!q.empty()) { // 队列不为空，说明还没遍历完
            int size = q.size(); // 确定当前层包含节点的个数，要用固定的，在循环过程中q的大小会变
            vector<int> vec; //用于保存当前层的结果
            for (int i = 0; i < size; i++) {  
                TreeNode* node = q.front();
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
                vec.push_back(node -> val);
            }
            res.push_back(vec);
        }
        return res;
    }
};