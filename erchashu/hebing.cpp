/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-27 19:52:18
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-27 20:13:29
 * @FilePath: /leet/erchashu/hebing.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    TreeNode* AddTwoTree(TreeNode* node1, TreeNode* node2) {
        TreeNode* node = new TreeNode();
        if (node1 && node2) {
            node -> val = node1 -> val + node2 -> val;
            node -> left = AddTwoTree(node1 -> left, node2 -> left);
            node -> right = AddTwoTree(node1 -> right, node2 -> right);
        } else if (node1 && !node2) {
            node -> val = node1 -> val;
            node -> left = AddTwoTree(node1 -> left, nullptr);
            node -> right = AddTwoTree(node1 -> right, nullptr);
        } else if (!node1 && node2) {
            node -> val = node2 -> val;
            node -> left = AddTwoTree(nullptr, node2 -> left);
            node -> right = AddTwoTree(nullptr, node2 -> right);
        } else {
            return nullptr;
        }
        return node;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return AddTwoTree(root1, root2);
    }
};