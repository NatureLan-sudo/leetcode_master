// 现在商店里有N个物品，每个物品有原价和折扣价。
// 小美想要购买商品。小美拥有X元，一共Y张折扣券。
// 小美需最大化购买商品的数量，并在所购商品数量尽量多的前提下，尽量减少花费。
// 你的任务是帮助小美求出最优情况下的商品购买数量和花费的钱数。
// 第一行三个整数，以空格分开，分别表示N,X,Y。
// 接下来N行，每行两个整数，以空格分开，表示一个的原价和折扣价。
// 1≤N≤100, 1≤X≤5000, 1≤Y≤50，每个商品原价和折扣价均介于[1,50]之间。
// 一行，两个整数，以空格分开。第一个数字表示最多买几个商品，第二个数字表示在满足商品尽量多的前提下所花费的最少的钱数。 9%
// 应该是背包dp，但是不会做了
//* 考试写的代码
#include <bits/stdc++.h>
using namespace std;
// int main() {
//     int n, x, y;
//     cin >> n >> x >> y;
//     vector<pair<int, int>> input(n);
//     for (int i =0; i < n; i++){
//         cin >> input[i].second >> input[i].first;
//     }
//     sort(input.begin(), input.end());
//     int num = 0;
//     int res = 0;
//     int qian = n;
//     for (int i = 0; i < n; i++) {
//         if (y && n >= input[i].first) {
//             y--;
//             n -= input[i].first;
//             num ++;
//         }
//         else if (!y && n >= input[i].second) {
//             n -= input[i].second;
//             num++;
//         }
//     }
//     cout << num << " " << qian - n << endl;
// }
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    // n 行数，x 是钱数，y是代金券数目
}