/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-25 16:48:17
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-25 16:48:17
 * @FilePath: /leet/erchashu/100相同的树.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 给出两棵树的根节点，判断两个树是否相等
class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr && q != nullptr) return false;
        else if (p != nullptr && q == nullptr) return false;
        else if (p -> val !=  q->val) return false;
        bool left = isSame(p -> left, q->left);
        bool right = isSame(p->right, q->right);
        return left&&right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    return isSame(p,q);
    }
};  