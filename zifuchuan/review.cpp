/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-18 15:21:35
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-18 16:47:08
 * @FilePath: /leet/zifuchuan/review.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    void reverseString(vector<char>& s) {
       int i = 0;
       int j = s.size() - 1;
       while (i <= j) {
        swap(s[i],s[j]);
        i++;
        j--;
       }       
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += (2 * k)) {
            if (i + k < s.length()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;

    }
};

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (auto i : s) {
            if (i == ' ') {
                count++;
            }
        }
        int i = s.length() - 1;
        s.resize(s.length() + 2 * count);
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%'; 
                j -= 3;
                i--;
            } else {
                s[j] = s[i];
                j--;
                i--;
            }
        }
        return s;
    }
};
// yuele 
class Solution {
public:
    string reverseWords(string s) {
        int num_of_space = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if (s[j] != ' ') {
                s[i] = s[j];
                i++;
            } else {
                num_of_space++;
            }
        }
        s.resize(s.length() - num_of_space);
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            
            
        }

    }
};
// reverse 的作用范围 ，左闭右开
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.end() - n);
        reverse(s.end() - n, s.end());
        return s;
    }
};