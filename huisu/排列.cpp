/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-08 16:22:17
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-08 16:59:09
 * @FilePath: /test/huisu/排列.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 排列问题不再需要startindex， for循环从0 开始
// 1、 全排列
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
// 之所以使用used就可以完成。是因为nums本身就不含重复数字。
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            } else continue;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;

    }
};
// 2、全排列II
// 数组中有重复的数字，，返回所有不重复的全排列
// 还要强调的是去重一定要对元素进行排序，这样我们才方便通过相邻的节点来判断是否重复使用了。
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue; // 同一个树层，上一个数字是重复的而且用过。因为到这里我们是回溯得到的，所以已经被改成false
            if (used[i] == true) continue; // 树枝取数字，排列，不允许重复使用一个数字
            path.push_back(nums[i]);
            used[i] = true; // 树枝
            backtracking(nums, used);
            used[i] = false; // 树层
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums,used);
        return result;
    }
};