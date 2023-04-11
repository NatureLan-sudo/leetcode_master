#include <bits/stdc++.h>
// 小美现在有一串彩带，假定每一厘米的彩带上都是一种色彩。
// 因为任务的需要，小美希望从彩带上截取一段，使得彩带中的颜色数量不超过K种。
// 显然，这样的截取方法可能非常多。于是小美决定尽量长地截取一段。
// 你的任务是帮助小美截取尽量长的一段，使得这段彩带上不同的色彩数量不超过K种
// 第一行两个整数N,K，以空格分开，分别表示彩带有N厘米长，你截取的一段连续的彩带不能超过K种颜色。
// 接下来一行N个整数，每个整数表示一种色彩，相同的整数表示相同的色彩。
// 1≤N,K≤5000，彩带上的颜色数字介于[1, 2000]之间。 100%
// 输出一行，一个整数，表示选取的彩带的最大长度。
// 维护一个滑动窗口，使得窗口内的色彩种类不超过K种
// 使用map记录，颜色有重复的次数
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int  result = 0;
    int  node = 0;
    map<int, int> key;
    for (int i = 0; i < n; i++) {
        key[input[i]]++; // 记录这种颜色出现的次数
        while (key.size() > k) { // 出现颜色的种类大于K种
            key[input[node]]--;  // 要把分割点弹出
            if (key[input[node]] == 0) key.erase(input[node]); // 分割点的颜色没了，删掉这个节点
            node++;
        } 
        result = max(result, i - node + 1); // 统计丝带长度
    }
    cout << result << endl;
}
// 使用set自动去重
// 是否要养成一个习惯？数字记录从下标1 开始，而不是0.用数组而不是vec.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int input[n +1];
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }
    int res = 0;
    set<int> key;
    for (int i = 1; i <= n; i++) {
        set<int> key;
        int j = i;
        while (j <= n) {
            key.insert(input[j]);
            if (key.size() > k) break;
            j++;
        }
        res = max(res, j - i);
    }
    cout << res << endl;
}