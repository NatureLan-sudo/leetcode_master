/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-27 19:29:55
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-27 19:47:22
 * @FilePath: /leet/erchashu/maxtree.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    TreeNode* maxtree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        // step 1 如果只有一个值，直接创造节点返回
        if (nums.size() == 1) {
            TreeNode* node = new TreeNode(nums[0]);
            return node;
        }
        // step 2 如果不只一个值，就找最大值
        int max_id = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[max_id]) {
                max_id = i;
            }
        }
        // step 3 根据最大值，创造节点
        TreeNode* node = new TreeNode(nums[max_id]);
        // step 4 分割最大值左右, 左闭右开
        vector<int> left_vec(nums.begin(), nums.begin() + max_id);
        vector<int> right_vec(nums.begin() + max_id + 1, nums.end());
        node -> left = maxtree(left_vec);
        node -> right = maxtree(right_vec);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return maxtree(nums);
    }
};