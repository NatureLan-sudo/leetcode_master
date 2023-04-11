#include <bits/stdc++.h>
using namespace std;
//* 最少的代金券数目
// 近期某商场由于周年庆，开启了“0元购”活动。活动中，消费者可以通过组合手中的代金券，实现0元购买指定商品。
// 聪明的小团想要用算法来帮助他快速计算：
// 对于指定价格的商品，使用代金券凑出其价格即可，但所使用的代金券总面额不可超过商品价格
// 由于代金券数量有限，使用较少的代金券张数则可以实现价值最大化，即最佳优惠。
// 假设现有100元的商品，而代金券有50元、30元、20元、5元四种，则最佳优惠是两张50元面额的代金券；
// 而如果现有65元的商品，则最佳优惠是两张30元代金券以及一张5元代金券。
// 这时候代金券的数量没有限制，但是我们需要得到最少的代金券数目
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     //* 输入
//     int price;
//     while (cin >> price) {
//         if (price == 0) break;
//         int N;
//         cin >> N;
//         vector<int> input(N);
//         for (int i = 0; i < N; i++) cin >> input[i];
//     //* 函数
//         vector<int> dp(price + 1, 100000);
//         // 代金券可以重复使用，所以是完全背包问题
//         // 价格为j 的时候，最少使用代金券的个数
//         dp[0] = 0; 
//         for (int i = 0; i < N; i++) { // 遍历代金券
//             for (int j = 1; j <= price; j++) { // 遍历价格
//                 if (input[i] > j) continue; // 代金券的数目大于price
//                 dp[j] = min(dp[j], dp[j - input[i]] + 1); // 不使用代金券，使用代金券
//             }
//         } 

//     //* 输出
//         if (dp[price] == 100000) cout << "Impossible" <<endl; // 如果是初始值说明没有解。
//         else cout << dp[price] << endl;
//     }
//     return 0;
// }
//* 代金券数目固定，有折扣价
// 在商店里有N个物品，每个物品有原价和折扣价小美相要购买商品。
// 小美拥有X元，一共Y张折扣券 小美需要最大化购买商品的数量，并在所购商品数量尽量多的前提下，尽量减少花费。 
// 你的任务是帮助小美求出最优情况下的商品购买数量和花费的钱数。
// 一行，两个整数，以空格分开。第一个数字表示最多买几个商品，第二个数字表示在满足商品尽量多的前提下所花费的最少的钱数。
// N <=100 ; 1 <= X <= 5000  ; 1 <= Y <= 50 
int main() {
    int N, X, Y;
    cin >> N >>X >>Y;
    vector<pair<int,int>> F(N);
    for (int i = 0 ; i < N; i++) {
        cin >> F[i].first >> F[i].second;
    }
    // dp[i][j][k] 前i个物品，花费j元，使用了k个优惠券，最多买几个商品
    // 对于一个商品 买或者不买，使用或者不使用优惠券
    // dp[i][j][k] =max (dp[i][j][k], max(dp[i][j + F[i].first][k], dp[i][j + F[i].second][k + 1]))
    // 如何初始化
    int dp[N][5005][55];
    int ans = 0; int money = 0;
    memset(dp, -1, sizeof(dp)); // 将dp数组填充为-1，因为要求max
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k <= Y; k++) {
                if (dp[i - 1][j][k] == -1) continue; //使用上一个状态更新当前，如果是-1说明是不可以到达的，继续下一个点
                if (j + F[i].first <= X) { // 当前按照原价可以购买这个商品。
                    // 原价买这个商品，看原来有没有这个值，如果从上一状态过来，买了这个商品+1，哪个买的多
                    dp[i][j + F[i].first][k] = max(dp[i][j + F[i].first][k], dp[i - 1][j][k] + 1); // 初始化是-1 
                    int t = dp[i][j + F[i].first][k];
                    if (t > ans)  {
                        ans = t;
                        money = j + F[i].first; // 钱
                    }
                    else if (t == ans)  {// 数目一样，比较钱更少
                        money = min(money, j + F[i].first);
                    }
                }
                if (j + F[i].second <= X && k != Y) { // 当前用优惠价格可以购买这个商品，并且代金券还有。
                    // 代金券买
                    dp[i][j + F[i].second][k + 1] = max(dp[i][j + F[i].second][k + 1], dp[i - 1][j][k] + 1);
                    int t = dp[i][j + F[i].second][k + 1];
                    if (t > ans)  {
                        ans = t;
                        money = j + F[i].second; // 钱
                    }
                    else if (t == ans)  {// 数目一样，比较钱更少
                        money = min(money, j + F[i].second);
                    }
                }
                // 其他情况，无论优惠还是原价都买不起这个商品,直接用上一个状态更新
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }
    cout << ans << " " << money << endl;
}