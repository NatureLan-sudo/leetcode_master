/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-21 11:13:39
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-21 11:38:47
 * @FilePath: /leet/zifuchuan/459.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
// 判断是不是由一个字符子串重复构成
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i * 2 <= s.size(); i++) {
            if (s.size() % i == 0) {
                bool mark = true;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] != s[j - i]) {
                        mark = false;
                        break;
                    }
                    
                }
                if (mark) {
                    return true;
                }

            }
        }
        return false;

    }
};