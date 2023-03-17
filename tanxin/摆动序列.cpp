/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-09 16:12:58
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-09 20:25:30
 * @FilePath: /test/tanxin/摆动序列.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"

// 贪心
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curdiff = 0;
        int prediff = 0;
        int result = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            curdiff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && curdiff > 0) ||(prediff >= 0 && curdiff < 0)) {
                ++result;
                prediff = curdiff;
            }
        }
        return result;
    }
};
// 这种数列，数字要么是山峰要么是山谷
// 动态规划解法
