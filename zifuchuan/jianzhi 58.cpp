/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-20 10:13:13
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-20 10:35:58
 * @FilePath: /leet/zifuchuan/jianzhi 58.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    void fanzhuan(string &s, int i, int j) {
        while ( i < j)
        {
           swap (s[i],s[j]);
           i++;
           j--;
        }   
    }
    string reverseLeftWords(string s, int n) {
        n = n % s.size(); //真正的 n; 
        //! 一定要注意取余数的顺序
        //翻转实现功能
        fanzhuan(s, 0, s.size()-1); // 整体反转
        fanzhuan(s, 0, s.size() - n -1);
        fanzhuan(s, s.size() - n, s.size() - 1);
        return s;
    }
};