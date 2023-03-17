/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-17 21:01:13
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-17 21:59:59
 * @FilePath: /test/真题/美团笔试题/美团前端202.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
//* 题目1
// 给定一个包含非负整数的 M x N 迷宫
// 请找出一条从左上角到右下角的路径，使得路径上的数字总和最小。每次只能向下或者向右移动一步。
using namespace std;
int main() {
  int m ,n;
  cin >> m >> n;
  vector<vector<int>> input(m, vector<int> (n));
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          cin >> input[i][j];
      }
  }
  vector<vector<int>> dp(m, vector<int>(n, 0));
  dp[0][0] = input[0][0];
  for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + input[0][j];
  for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + input[i][0];
  for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + input[i][j];
      }
  }
  cout << dp[m - 1][n - 1] <<endl;
}
// 通过全部用例
//* 题目2
// 代金券组合,不能直接贪心，因为要代金券使用数量最少
// 输入为0 的时候代表用例结束
#include <bits/stdc++.h>
using namespace std;
int main() {
    int target;
    while (cin >> target) {
        if (target == 0) break;
        int zhonglei;
        cin >> zhonglei;
        vector<int> input(zhonglei);
        for (int i = 0; i < zhonglei; i++) {
            cin >> input[i];
        }
        vector<int> dp(target + 1, 100000); // 因为要求最小，所以这时候初始化为大值。
        dp[0] = 0;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < zhonglei; j++) {
                if (i >= input[j]) {
                    dp[i] = min (dp[i], dp[i - input[j]] + 1);
                }
            }
        }
        if (dp[target] == 100000) cout << "Impossible" << endl;
        else cout<< dp[target] << endl;
    }
    return 0;
}