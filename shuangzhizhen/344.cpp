/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-24 21:38:49
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-24 21:42:44
 * @FilePath: /leet/shuangzhizhen/344.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
// 实现字符串反转
#include "common_include.h"
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

    }
};