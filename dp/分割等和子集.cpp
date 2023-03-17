/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-17 15:59:52
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-17 16:44:32
 * @FilePath: /test/dp/分割等和子集.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &i : nums) {
            sum += i;
        }
        sum = sum / 2;
        // 找到一组数字加和为sum/2就可以。
        // 抽象为背包问题，价值和重量是相等的. 背包容量为j的时候，最大价值的d[j],如果d[j] = j,说明背包装满了。
        vector<int> dp(sum + 1, 0);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) { // 数字个数
            for (int j = sum; j >= nums[i]; j--) {   // 背包容量
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum] == sum ? 1 : 0;
    }
};
int main() {
    vector<int> input;
    int a;
    while (cin >> a) {
        input.push_back(a);
    }
    
}