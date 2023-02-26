/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-28 12:57:58
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-28 13:54:40
 * @FilePath: /leet/zhanyuduilie/1047.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
#include <stack> 
// 为什么这个是典型的栈，因为我们是想和最后一个元素比，想方便的把最后一个元素给剔除了 这就是栈啊
// 队列是把最老的元素踢出去
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> key;
        int i = 0;
        int len = s.size();
        while (i < s.size()) {
            if(!key.empty()) { // 栈不为空才行
                if (s[i] == key.top()) {
                 key.pop();
                 len = len -2;
                } 
                else 
                {
                key.push(s[i]);
                }
            }
            else{
                key.push(s[i]);
            }
            i++;
        }
        string res;
        while (!key.empty()) {
            res += key.top();
            key.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};