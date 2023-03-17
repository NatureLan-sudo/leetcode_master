/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-17 17:20:32
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-17 17:53:57
 * @FilePath: /test/真题/百度笔试题/3.13暑期实习笔试.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;
// 字符串异或

// 删除游戏

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    int count[100000];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        count[input[i]]++; // 记录这个数字出现的次数， 可能不止出现一次
    }
    // 完成输入
    vector<vector<int>> dp(2, vector<int>(input.size()));
    dp[0][0] = 0; dp[0][1] = 0;
    for (int i = 1; i <= 100000; i++) {
        // dp[0][i]代表只考虑不大于i的数，并且没有操作等于i
        // dp[1][i]代表只考虑不大于i的数，操作i
        // 不操作i,看上一个数操作大，还是不操作大，如果操作了数，当前的数就被删掉了，就不能操作。
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        // 操作i, 那么上一个数只能不操作。
        dp[1][i] = dp[0][i - 1]+ i*count[i];
    }
    cout << dp[0][100000]<<endl;
    return 0;
}