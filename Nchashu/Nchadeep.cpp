/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-19 08:57:44
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-19 09:30:38
 * @FilePath: /leet/Nchashu/Nchadeep.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//
class Solution {
public:
    int getdepth (Node* node) {
        // end
        if (node == nullptr) return 0;
        // 
        int depth = 0;
        for (int i = 0; i < node -> children.size();i++) {
            depth= max(depth,getdepth(node -> children[i]));
        }
        return depth +1;  
    }
    int maxDepth(Node* root) {
        return getdepth(root);
    }
};
// 
class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        if (root == nullptr) return 0;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            depth ++;
            for (int i = 0; i < size ;i++) {
                Node* node = q.front();
                q.pop();
                for (int j = 0; j < node->children.size();j++) {
                    if (node -> children[j]) q.push(node -> children[j]);
                }
            }
        }
        return  depth;

    }
};