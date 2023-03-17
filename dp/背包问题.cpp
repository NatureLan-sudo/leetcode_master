/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-15 16:12:54
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-15 19:32:24
 * @FilePath: /test/dp/背包问题.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
// 对于面试，需要掌握 0-1背包和完全背包
#include <bits/stdc++.h>
//* 0-1背包
// 有n件物品和一个最多能背重量为w 的背包。
// 第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
using namespace std;
// 二维数组解决
void solvebag(int bagweight, vector<int> &weight, vector<int> &value) {
    // 初始化dp数组全部为0，使用vec！
    vector<vector<int>> dp(weight.size(),vector<int>(bagweight + 1, 0)); 
     // dp[i][j],从下标为0-i的物品里任意取，放进容量为j的背包，价值总和最大是多少
    // 两种状态，放物品或者不放物品。
    // 因为我们当前状态放了物品，说明之前的状态是没有放物品。所以j是去掉当前物体i重量的dp[i-1][j - wight[i]]
    // 放物品   dp[i][j] = dp[i-1][j - wight[i]] + value[i];
    // 不放物体，dp[i][j] = dp[i-1][j]
    // 方程：
    for (int i = 0; i <= weight.size(); i++) dp[i][0] = 0;
    for (int j = weight[0]; j <= bagweight; j++) dp[0][j] = value[0];
    for (int i = 1; i < weight.size(); i++) { // 遍历物品
        for (int j = 0; j <= bagweight; j++) { // 遍历背包重量,
            if (j < weight[i]) dp[i][j] = dp[i - 1][j]; // 当前背包重量放不下这个物品
            // 放或者不放这个物体
            else dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);

        }
    }
    cout << dp[weight.size() - 1][bagweight] <<endl;
}
//* 一维滚动数组解决
void solvebag(int bagweight, vector<int> &weight, vector<int> &value) {
    // 覆盖上一层进行；
    vector<int> dp(bagweight + 1, 0); // 背包容量为j时候的最大值
    for (int i = 0; i < weight.size(); i++) {
        for (int j = bagweight; j >= weight[i]; j--) { // 倒序遍历，因为会有状态覆盖，如果正序会多次加入一个物体
            // 放物体，或者不放物体
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagweight] << endl;

}
int main() {
    int n, w;
    cin >> n >> w;
    vector<int> wight(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++) cin >> wight[i];
    for (int j = 0; j < n; j++) cin >> value[j];
}