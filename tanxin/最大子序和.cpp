/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-09 20:26:00
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-09 21:39:09
 * @FilePath: /test/tanxin/最大子序和.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) {
                result = count; // 记录出现过的最大值,即便后面加到负数，count变小了也么关系，因为我们只把最大值赋给result
            }
            if (count < 0) count = 0; // 连续变负数了，那么需要重新开始序列
        }
        return result;

    }
};