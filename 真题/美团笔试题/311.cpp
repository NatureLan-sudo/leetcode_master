/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-17 15:50:37
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-19 22:06:45
 * @FilePath: /test/真题/美团笔试题/311.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
// #include <bits/stdc++.h>
// using namespace std;
//* 1
// 小美有一个由数字字符组成的字符串。现在她想对这个字符串进行一些修改。 
//具体地，她可以将文个字符串中任意位置字符修改为任意的数字字符。她想知道，至少进行多少次修改，可以使得“修改后的字符串不包含两个连续相同的字符?
// 例如，对于字符串”111222333", 她可以进行3次修改将其变为” 121212313"。输入描述
// 一行，一个字符串s，保证s只包含数字字符。1<=|s|<= 100000输出描述
// 一行，一个整数，表示修改的最少次数。
// int main() {
//     string input;
//     cin >> input;
//     int res = 0;
//     if (input.size() <= 1) cout << 0 << endl;
//     for (int i = 1; i < input.size(); i++) {
//         if (input[i] == input[i - 1]) {
//             input[i] = '+';
//             res++;
//         } 
//     }
//     cout << res << endl;
// }

//* 2
// 小美是一位天文爱好者，她收集了接下来段时间中所有会划过她所在的观测地上空的流星信息。
// 具体地，她收集了 n 个流星在她所在观测地上空的出现时刻和消失时刻，对于一个流星，若其的出现时换为 s ，消失时刻为 t ，那么小美在时间段 [s,t] 都能够观测到它。
// 对于一个时刻， 观测地上空出现的流星数量越多，则小美认为该时刻越好。
// 小美希望能够选择一个最佳的时刻进行观测和摄影，使她能观测到最多数量的流星，现在小美想知道，在这个最佳时刻，她最多能观测到多少个流星以及一共有多少个最佳时刻可供她选择。
// 第一行是一个正整数 n ，表示流星的数量。
// 第二行是 n 个用空格隔开的正整数，第 i个数 si 表示第 i 个流星的出现时间。
// 第三行是 n 个用空格隔开的正整数，第 i 个数 ti 表示第 i 个流星的消失时间。
// 1≤n≤100000,1≤si≤ti≤109
// 输出描述
// 输出一行用空格隔开的两个数 x 和 y ，其中 x 小美能观测到的最多流星数， y 表示可供她选择的最佳时刻数量。
// 3
// 2 1 5
// 6 3 7
// n是流星的数目，属于框定最小最大空间
// md 超时了。
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> s(N);
    vector<int> t(N);
    vector<pair<int, int>> key;
    int kaishi = 10000;
    int jieshu = -1;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        kaishi = kaishi > s[i] ? s[i] : kaishi;
    }
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        jieshu = jieshu < t[i] ? t[i] : jieshu;
    }
    for (int i = 0; i < N; i++) {
        int a = s[i];
        int b = t[i];
        key.emplace_back(a, b);
    }
//    sort(key.begin(), key.end());
    int max_guance = 0;
    int numofshike = 0;
    for (int i = kaishi; i <= jieshu; i++) {
        // 遍历时刻
        int max = 0;
        int num = 0;
        for (int j = 0; j < N; j++) { // 遍历流星出现消失的时间。
            // cout<< key[j].first <<key[j].second <<endl;
            if (i >= key[j].first && i <= key[j].second) {
                max++;
            }
        }
        if (max > max_guance) { // 观测数目更新；
            max_guance = max;
            numofshike = 1;
        } else if (max == max_guance) {
            numofshike ++;
        } 
    }
    cout << max_guance << " " << numofshike << endl;
}
// 3
// 2 1 5
// 6 3 7