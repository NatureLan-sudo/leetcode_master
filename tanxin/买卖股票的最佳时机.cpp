/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-09 21:06:11
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-09 21:39:06
 * @FilePath: /test/tanxin/买卖股票的最佳时机.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 如果手里有股票 必须卖了 才能买新的
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int guopiao = 0;
        for (int cur = 0; cur < prices.size() - 1; cur++) {
            if (prices[cur] < prices[cur + 1]) {// 未持有，买
                if (guopiao == 0) {
                    guopiao -= prices[cur];
                }
                // 正在持有，不卖
                // 最后一天必须得卖了
                if (cur = prices.size() - 2 && guopiao != 0) {
                    res = guopiao + prices[cur + 1];
                    guopiao = 0;
                }
            }
            if (prices[cur] > prices[cur + 1]) {
                if (guopiao != 0) {// 持有，卖了
                    res = guopiao + prices[cur];
                    guopiao = 0;
                }
                // 未持有，不操作
            }
        }
        return res;

    }
};