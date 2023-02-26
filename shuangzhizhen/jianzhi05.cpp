/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-24 21:43:20
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-24 22:17:10
 * @FilePath: /leet/shuangzhizhen/jianzhi05.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
//替换空格为%20；
class Solution {
public:
    string replaceSpace(string s) {
        // 1.计算空格数
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // 2.扩张原来的数组 resize()
        s.resize(s.size() + count * 2);
        // 3.遇到空格替换,这个比较奇特，是倒着来的因为我们是要插入。应该是插入都要倒着。
        int i = s.size() - 1;
        int j = i - count * 2;
        while (i > j) {
            if (s[j] == ' ') {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i = i -3;
            } else {
                s[i] = s[j];
                i--;
            }
            j--;
        }
        return s;
    }
};