/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-24 21:33:10
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-24 21:36:49
 * @FilePath: /leet/shuangzhizhen/27.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
// 使用双指针法

#include "common_include.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] == val) {
                j++;
            }else {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};