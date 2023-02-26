/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-19 19:52:19
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-19 21:07:00
 * @FilePath: /leet/erchashu/完全二叉树.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
// 返回完全二叉树的节点个数

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 完全二叉树：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
// 题目保证输入的是完全二叉树
// 按照普通二叉树来处理，通过层序遍历，其实通过其他遍历也没太大关系
// 按照普通二叉树来处理的话,就没什么难度,遍历一下就行了.
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr) return 0;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                res++;
                if (node -> left) q.push(node -> left);
                if (node ->right) q.push(node ->right);
            }
        }
        return res;
    }
};

class Solution {
    public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftdepth = 1;
        int rightdepth = 1;
        while (root -> left) {
            leftdepth++;
            root = root -> left;
        }
        while (root -> right) {
            rightdepth++;
            root = root -> right;
        }
        if (leftdepth == rightdepth) { // 说明是满二叉树,如果是满二叉树,直接计算出结果就好了
            return 2<<(leftdepth - 1) - 1; // 满二叉树的节点个数
        }
        // 如果不是满二叉树,就向下找
        return countNodes(root -> left) + countNodes(root ->left) + 1;
    }
};

//利用完全二叉的性质实现, 其他层数都是满的,并且最后一层满的在左边,空的在右边,那么除了最后一层之外,节点的数量我们是可以计算出来的
// 直接这样计算会导致代码比较冗余,我们需要去判断最后一层有几个节点,那么还是从层序遍历的出来的最,就没必要了
// 完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。
// 对于情况一，可以直接用 2^树深度 - 1 来计算，注意这里根节点深度为1。
// 对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后依然可以按照情况1来计算。
// 如何判断是一颗满二叉树 在完全二叉树中，如果递归向左遍历的深度不等于递归向右遍历的深度，则说明不是满二叉树
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftdepth = 1;
        int rightdepth = 1;
        while (root -> left) {
            leftdepth++;
            root = root -> left;
        }
        while (root -> right) {
            rightdepth++;
            root = root -> right;
        }
        if (leftdepth == rightdepth) { // 说明是满二叉树,如果是满二叉树,直接计算出结果就好了
            return 2<<(leftdepth - 1) - 1; // 满二叉树的节点个数
        }
        // 如果不是满二叉树,就向下找
        return countNodes(root -> left) + countNodes(root ->left) + 1;
    }
};

//神级递归
class Solution {
public:
    int res = 0;
    int countNodes(TreeNode* root) {
        if (root) {
            res++;
            countNodes(root ->left);
            countNodes(root ->right);
        }
        return res;
    }
};
