/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-08 13:41:27
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-08 16:21:40
 * @FilePath: /test/huisu/子集.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 数组无重复元素
class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    void backtracking(vector<int>& nums, int startIndex) {
        // 不需要条件直接加入。
        result.push_back(subset);
        // 递归终止。
        if (startIndex >= nums.size()) return; // 说明已经取到叶子节点
        for (int i = startIndex; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtracking(nums, i + 1);
            subset.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return result;
        backtracking(nums, 0);
        return result;
    }
};
// 数组有重复元素
// 树层去重、树枝去重
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used) {
        result.push_back(path);
        if (startIndex == nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i-1] == false) continue; //　上一个用过！跳过本次循环
            path.push_back(nums[i]);
            used[i] = true; // 树枝重复
            backtracking(nums, i + 1, used);
            used[i] = false;  // 树层重复
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return result;
    }
};
// 递增子序列
// 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
// 1、有条件的子集  2、基于数组的自增子序列，并不是排序好的，也不能排序，需要新的去重思路
// 也是同一个树层，不能重复使用相同 
// 到达叶子节点，也就是nums取空的时候就结束了
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) result.push_back(path); // 所有节点遍历
        if (startIndex == nums.size()) return;
        unordered_set<int> used; // 只负责本层的横向遍历
        for (int i = startIndex; i < nums.size(); i++) {
            // 首先判断去重
            // 而后判断自增
            if ((!path.empty() && nums[i] < path[path.size() - 1])|| used.find(nums[i]) != used.end()) { // 不是自增
                continue;
            } 
            used.insert(nums[i]); // 记录在本层用过
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       backtracking(nums, 0);
       return result;
    }
};