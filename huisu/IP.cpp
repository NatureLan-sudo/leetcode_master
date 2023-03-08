/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-08 12:43:46
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-08 13:33:07
 * @FilePath: /test/huisu/huisu.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 每个整数在0-255之间，不能有前导0，每个数用.分开
// 不能重新排序或者删除任何数字
// 如何处理前导0
class Solution {
public:
    vector<string> result;
    bool isvalid(string s, int start, int end) {
        // 前导0不合法
        // 大于255不合法
        // 出现不是正整数的数字不合法
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') return false;
        }
        int num = std::stoi(s.substr(start, end - start + 1));
        if (num > 255) return false;
        return true;
    }
    // 因为要插入分割“.” ， 所以在s的基础上进行操作。
    void backtracking(string &s, int startIndex, int numofpoint) {
        if (numofpoint == 3) {
            if (isvalid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isvalid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.'); // 在第一个值前加入字符’.‘
                numofpoint++;
                backtracking(s, i + 2, numofpoint);
                numofpoint--;
                s.erase(s.begin() + i + 1);
            } else break; // 不合法直接结束循环
        }


    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};