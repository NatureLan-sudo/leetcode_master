/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-19 12:54:34
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-19 17:39:52
 * @FilePath: /test/真题/美团笔试题/318shuqi/1.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
// 小美在玩一项游戏。该游戏的目标是尽可能抓获敌人。
// 敌人的位置将被一个二维坐标 (x, y) 所描述。
// 小美有一个全屏技能，该技能能一次性将若干敌人一次性捕获。
// 捕获的敌人之间的横坐标的最大差值不能大于A，纵坐标的最大差值不能大于B。
// 现在给出所有敌人的坐标，你的任务是计算小美一次性最多能使用技能捕获多少敌人。
// 第一行三个整数N,A,B，表示共有N个敌人，小美的全屏技能的参数A和参数B。
// 接下来N行，每行两个数字x,y，描述一个敌人所在的坐标。
// 1≤N≤500，1≤A,B≤1000，1≤x,y≤1000。  36%
// 利用二维前缀和统计，到[i][j]出现元素的个数，利用A、B框选范围，计算矩形内出现了多少元素（敌人）
// 需要考虑边界以及重复敌人的问题。
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int g[1005][1005];
    for (int i =0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y]++;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            g[i][j] = g[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    } // 计算二维前缀表

    int res = 0;

    // 框选矩形框
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            int tmp = g[i][j] - g[max(0, i - a -1)][j] - g[i][max(0, j - b -1)] + g[max(i - a - 1, 0)][max(j - b - 1, 0)];
            res = max(tmp, res);
        }
    }

    cout << res << endl;
    return 0;
} 