/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-15 14:17:10
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-15 16:13:38
 * @FilePath: /test/dp/不同的二叉搜索树.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;
// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
// 回忆什么是二叉搜索树，左边的都小于中间节点，右边的都大于中间节点，中序排列是递增的
//  1 <= n <= 19
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        // dp[i] 代表在节点数为N的时候构成的二叉搜索树
        // 找到重叠子问题
        // dp[3] 可以由 dp[1]和dp[2]算出来
        for (int i = 1; i <= n; i++) { // i 代表节点数
            for (int j = 1; j <= i; j++) {
                // i节点的状态由前面节点的累加决定
                // dp[3] = dp[0]*dp[2] + dp[1] * dp[1]+ dp[2] *dp[0];
                dp[i] += dp[j - 1] * dp[i - j];

            }
        }
        return dp[n];
    }
};