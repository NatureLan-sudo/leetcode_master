/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-26 10:22:26
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-26 11:20:17
 * @FilePath: /leet/zhanyuduilie/20.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
#include <stack>

// 括号种类比较少，是自己做了匹配
class Solution {
public:
    bool isValid(string s) {
    // 1、由于字符串只包括括号，所以如果奇数，那么一定是不满足条件的 
    if (s.size()%2 != 0) return false;
    // 2、使用栈，做配对
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] =='[') {
            st.push(s[i]);
        } else {
            if (!st.empty()) { // 如果不为空才进行右括号匹配
                if (s[i] == ')') {
                if (st.top() != '(') return false;
                st.pop();
            }
             if (s[i] == '}') {
                if (st.top() != '{') return false;
                st.pop();
            }
             if (s[i] == ']') {
                if (st.top() != '[') return false;
                st.pop();
            }
            }else { // 如果为空还来右括号说明是错的
                return false;
            }
        }
    }
    return st.empty();

    }
};

