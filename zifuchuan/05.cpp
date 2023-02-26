/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-19 09:18:08
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-19 09:41:23
 * @FilePath: /leet/zifuchuan/05.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    string replaceSpace(string s) {
    int count = 0; // 空格的数量
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') count++;
    }
    s.resize(s.length()+count*3);
    int i = s.size() - 1;
    int j = i - count;
    while (i > j) {
        if (s[j] == ' ') {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i = i - 3;
        }
        else {
            s[i] = s[j];
            i--;
        }
        j--;
    }
    return s;
 }
};