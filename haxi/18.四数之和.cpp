/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-15 15:40:17
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-15 15:40:18
 * @FilePath: /leet/haxi/18.四数之和.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 如果不进行超出范围的break可能会超时？
            if (nums[i] > target && nums[i] > 0) return result;  
            //必须判断是不是大于0如果不是，例如target=-3，nums[i] = -2,则丢了-1
            if (i > 0 && nums[i - 1] == nums[i]) continue; // 一组去重
            for (int j = i + 1; j < nums.size(); j++) {
                int left = j + 1;
                int right = nums.size() - 1;
                //if (nums[j] == nums[j + 1]) continue;
                if (nums[i] + nums[j] > target && nums[i] + nums[j] > 0) break;
                if (j > i + 1 && nums[j - 1] == nums[j]) continue; //二组去重
                while (left < right) {
                    // 要加long 不然会报执行出错，因为所有数都是int型，可能相加会超出int范围
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else {
                        result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1]) right--; // 组内去重
                        while (left < right && nums[left] == nums[left+1]) left++;
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
