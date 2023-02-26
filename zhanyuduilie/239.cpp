/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-09 17:52:14
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-10 09:02:52
 * @FilePath: /leet/zhanyuduilie/239.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。

#include "common_include.h"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dan; // 存编号
        // 队列中维护的是编号
        for (int i = 0; i < nums.size(); i++) {
            // 维护一个大小为k的窗口，等于K的时候就要把最前面的值弹出去
            if (i - dan.front()  >= k && !dan.empty()) {
                dan.pop_front();
            }
            // 只要队尾的比新来的值小，那么就要被淘汰了
            while (!dan.empty() && nums[dan.back()] < nums[i]) {
                dan.pop_back();
            }
            dan.push_back(i);
            if (i - k >= -1)  { // 当满足窗口条件后，每次都把最大的放到输出中
                ans.push_back(nums[dan.front()]);
            }
        }
        return ans;
    }
};