/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-20 10:39:21
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-21 11:29:08
 * @FilePath: /leet/zifuchuan/28.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
// 在一个串中查找是否出现过另一个串
// KMP的经典思想就是:当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
//链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string
// 说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
class Solution {
public:
    void getNext(int *next, const string &needle) {
        // 初始化,计算不减1的前缀表
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < needle.size();i++) {
            // 由于不相等要回退到上一个值，所以j需要大于0。当元素不相等的时候就一直向前回退，直到回退到相等的位置
            while (j > 0 && needle[j] != needle[i]) {
                j = next[j - 1]; //回退到上一个元素的值
            }
            if(needle[j] == needle[i]){
                j++;
            }
            next[i] = j; // 记录当前的next值，是j++，因为我们取的时候是取前一个元素的值
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;  // 当needle为空字符串时候
        if (haystack.size() < needle.size()) return -1; // 大字符串反而小于小字符串的时候，直接返回不存在。
        int next[needle.size()];
        getNext(next, needle); //注意数组操作要用指针
        // 在文本串中找模式串
        int j = 0; // 指向模式串
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == needle.size()) return i - needle.size() + 1;
        }
        return -1;
    }
};