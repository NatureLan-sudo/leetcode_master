/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-19 13:16:56
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-19 14:35:11
 * @FilePath: /test/dp/494.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
// 构造一个表达式，使得，表达式的值等于target
// 每个数只能用一次，所以01背包
// 在求装满背包有多少种方法的时候，dp[j] = dp[j] + dp[j - nums[i]];
// acm 和 核心代码模式不太一样，如果是核心代码模式，不要设特别大的初始化数组，而是要根据到底有多少数
using namespace std;
int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto &i : nums) {
            sum += i;
        }
        // x -(sum - x) = target  x= (sum + target) / 2
        if (sum < abs(target)) return 0;
        if ((sum + target) % 2 != 0) return 0;
        int bagsize = (sum + target) / 2;
        int dp[1005];
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagsize; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[bagsize];
}
int main() {
    int target;
    cin >> target;
    vector<int> nums;
    int a;
    while(cin >> a) {
        nums.push_back(a);
    }
    cout << findTargetSumWays(nums, target) << endl;

}