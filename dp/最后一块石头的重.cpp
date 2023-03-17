/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-17 16:44:14
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-17 17:22:29
 * @FilePath: /test/dp/最后一块石头的重.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include<bits/stdc++.h>
// 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
// 物品重量和价值一样。
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
      // 尽量将石头分成重量相同的两堆，相撞后，剩下的最小。
      int sum = 0;
      for (auto &i : stones) {
        sum += i;
      }
      // 如果两堆刚好一样大最好。如果不是就返回相差的数。
      int target = sum / 2;  // 向下取整
      vector<int> dp(target + 1, 0);
      for (int i = 0; i < stones.size(); i++) {
          for (int j = target; j >= stones[i]; j--) {
              dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
          }
      }
      return (sum - dp[target])- dp[target];
    }
};