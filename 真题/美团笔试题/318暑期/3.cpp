/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-19 12:54:42
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-19 20:56:12
 * @FilePath: /test/真题/美团笔试题/318shuqi/3.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
// 现在小美获得了一个字符串。小美想要使得这个字符串是回文串。
// 小美找到了你。你可以将字符串中至多两个位置改为任意小写英文字符’a’-‘z’。
// 你的任务是帮助小美在当前制约下，获得字典序最小的回文字符串。
// 数据保证能在题目限制下形成回文字符串。
// 注：回文字符串：即一个字符串从前向后和从后向前是完全一致的字符串。
// 例如字符串abcba, aaaa, acca都是回文字符串。字符串abcd, acea都不是回文字符串。
// 一行，一个字符串。字符串中仅由小写英文字符构成。
// 保证字符串不会是空字符串。
// 字符串长度介于 [1, 100000] 之间。   输出字典序最小的回文串  ac:64
#include <bits/stdc++.h>
using namespace std;
// 重写算法
int main() {
    string input;
    cin >> input;
    vector<pair<int,int>> gaidong;
    int i = 0; 
    int j = input.size() - 1;
    while (i < j) {
        if (input[i] != input[j]) {
            gaidong.emplace_back(i, j);
            if (input[i] > input[j]) input[i] = input[j];
            else input[j] = input[i];
        }
        i++;
        j--;
    }
    // for (int i = 0; i < gaidong.size(); i ++) {
    //     cout << gaidong[i].first << " "<<gaidong[i].second << endl;
    // }
    bool jishu = input.size() % 2;
    // acaca 1   
    if (gaidong.size() == 0) {
        for (long int i = 0; i < input.size(); i++) {
            if (input[i] != 'a') {
                input[i] = 'a';
                input[input.size() - i - 1] = 'a';
                break;
            }
        }
    } // aacaa  5
    if (gaidong.size() == 1) {
        if (jishu) {
            if (input[gaidong[0].first] == 'a') {
                input[(input.size() / 2)] = 'a';
            }          
        }
        input[gaidong[0].first] = 'a';
        input[gaidong[0].second] = 'a';
        
    }
    cout << input << endl;
    return 0;
}

//
// int main() {
//     string input;
//     cin >> input;
//     int length = input.size() - 1;
//     int halfoflen = input.size() / 2;
//     int count = 0;
//     vector<int> gaidong(2);
//     for (int i = 0, j = length; i <=halfoflen, j >=halfoflen; i++, j--) {
//         if (input[i] == input[j]) continue;
//         if (input[i] < input[j]) input[j] = input[i];
//         else input[i] = input[j];
//         gaidong.push_back(i);
//         count++;
//     }
//     if (count == 1) {
//         input[gaidong[0]] = 'a';
//         input[length - gaidong[0]] = 'a';
//     }
//     // if (count == 0) {
//     //     int max_char = 0;
//     //     for (int i = 1; i < halfoflen; i++) {
//     //         if (input[i] > input[max_char]) max_char = i;
//     //     }
//     //     input[max_char] = 'a';
//     //     input[length - max_char] = 'a';
//     // } 
//     if (count == 0) { // 改后
//         for (int i = 0; i <= halfoflen; i++) {
//             if (input[i] != 'a') {
//                 input[i] = 'a';
//                 input[length - i] = 'a';
//                 break;
//             }
//         }
//     }
//     cout << input <<endl;
// }
// 自己的算法应该是漏了东西，可能是字典序没有理解到，我认为是加起来总和最小。但实际上是按顺序，遇到不等于a的就给改了,所以在等于0的时候应该改为遇到a就改，并且没有考虑奇数偶数，导致通过率一直没达到
