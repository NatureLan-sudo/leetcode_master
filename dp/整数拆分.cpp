/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-15 13:56:14
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-15 14:16:39
 * @FilePath: /test/dp/整数拆分.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;
// 感觉数组有初始化问题，还是用vec好
class Solution {
public:
    int integerBreak(int n) {
        // 拆分成至少两个整数并使得乘积最大。
        // 从1 开始 拆到目标数  
        // dp[i] 代表 i时候的最大乘积
        // dp[i] = max (dp[i - j]* j , (i - j) * j)
       vector<int> dp(n+1);
        dp[2] = 1;
        // 注意n的范围条件
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                // dp[i], 需要取最大值更新，不能每次都变一下
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));

            }
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    Solution A;
    int res = A.integerBreak(n);
    cout << res << endl;
}