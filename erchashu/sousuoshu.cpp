/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-27 20:14:09
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-27 22:32:19
 * @FilePath: /leet/erchashu/sousuoshu.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 二叉搜索树的性质，若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
// 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
// 它的左、右子树也分别为二叉搜索树
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root -> val == val) return root;
        if (root -> val < val) {
            // 别忘了有返回值                     
           return searchBST(root -> right, val);
        }
        if (root -> val > val) {
           return searchBST(root -> left, val);
        }
        return nullptr;
    }
};
// 判断是否是有效的搜索
// 下面这个代码是错误的，因为这样的话，智能保证在某个根节点下满足要求，但是整个左树或右树不满足要求。
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = false;
        bool right = false;
        if (root -> left && root -> val > root -> left -> val) {
            left = true;
        }
        if (root -> right && root -> val < root -> right -> val) {
            right = true;
        }
        return isValidBST(root -> left) && isValidBST(root -> right);
    }
};
// 搜索树的中序遍历是有序的  递增序列  
// 也可以中序遍历递归 
// 也是利用中序遍历的规律
class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root -> left);
        if (pre != nullptr && pre -> val >= root -> val)  return false;
        else pre = root;
        bool right = isValidBST(root -> right);
        return left && right;
    }
};

// 搜索树的最小绝对值差
// 先遍历出一个vector<int> 然后直接相邻相减
class Solution {
public:
    vector<int> res;
    void travel(TreeNode* root) {
        if (root == nullptr) return;
        travel(root -> left);
        res.push_back(root -> val);
        travel(root -> right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return 0;
        travel(root);
        if (res.size() < 2) return 0;
        int min = abs (res[1] - res[0]);
        for (int i = 1; i< res.size(); i++) {
            if (abs(res[i] - res[i-1]) < min)
                min = abs(res[i] - res[i-1]);
        }
        return min;
    }
};