/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-19 09:42:24
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-19 12:54:28
 * @FilePath: /leet/zifuchuan/151.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
class Solution {
public:
    string quchukongge(string s) {
        int count = 0; // 记录需要resize的大小
        int i = 0;
        int j = 0;
        // 去除开头的空格
        while (s.size() > 0 && j < s.size() && s[j] == ' ') {
            j++;
        }
        // 去除中间的空格
        while (j < s.size() ) {
            if (j-1 >0 && s[j] == ' ' && s[j - 1] == ' '){
                j++;
            }
            else {
                s[i++] = s[j];
                j++;
            }
        }
        // 去除末尾
        if ( i - 1 >0 && s[i - 1] == ' ') {
            s.resize(i-1);
        }else
        {
        s.resize(i);
        }
        return s;
    }
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭又闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseWords(string s) {
        s = quchukongge(s);
        //! 特别需要注意，在函数外定义函数，调用参数的时候，如果要有返回值，要用等于号引过来
        //! 如果不通过赋值，想直接用void, 那么函数在定义的时候就必须 采用引用的方式
        // void quchukongge(string & s) 
        // 这样 引用 就相当于直接对输入量进行操作了，不需要进行赋值，因为操作的是同一个地址
        reverse(s, 0, s.size()-1); // 翻转整个字符串
        // 遇到空格，反转小字符串
        // 到最后一个字符的时候，需要再进行一次反转，因此，需要有等于边界这一项
        int i = 0, j = 0; //
        while (j <= s.size()) {
            if (s[j] == ' '|| j==s.size()) {
                reverse(s, i, j-1);
                j++;
                i = j;
            }else {
                j++;
            }
        }
        return s;
    }
};
int main() {
    Solution s;
    string s1 = " hello world ";
    string s2 = s.reverseWords(s1);
    cout << s2 <<endl;

}