/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-11 14:45:58
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-20 11:22:27
 * @FilePath: /test/inandout.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
// TODO
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;
// 一行一个数字，输入两行
int main() {
    int n, m;
    cin >> n;
    cin >> m;
    cout << n << endl;
    cout << m << endl;
    return 0;
}

// 一行两个数字，多行输入
int main () {
    int n, m;
    while (cin >> n >> m) {
        // 函数处理
        // 输出结果
    }
    return 0;
}
// 第一行包括数组组数，接下来每行包括两个正整数
int main () {
    int n;
    int a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        // 函数处理
        // 函数输出
    }
    return 0;
}
// 第一行是一个整数k，第二行有k个整数
int main() {
    int k;
    cin >> k;
    vector<int> input(k);
    for (int i = 0; i < k; i++) {
        cin >> input[i];
    }
    cout << k <<endl;
    for (auto &i : input) {
        cout << i << " ";
    }
    cout <<endl;
    return 0;
}

// 两个整数， 输入数据有多组，如果输入为00， 则结束输入
int main() {
    int n, m;
    while (cin >> m >> n) {
        if (m ==0 && n == 0) break;
        // 函数处理
        // 函数输出
    }
    return 0;
}
// 一行未知个数的整数 中间是空格隔开
int main() {
    vector<int> nums;
    int a;
    while(cin >> a) {
        nums.push_back(a);
    }
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
// 一行未知个数的证书，中间是， \ ，空格隔开
int main() {
    vector<int> nums;
    int a;
    while(cin >> a) {
        nums.push_back(a);
        if (cin.get() == '\n') break;
    }
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
// 输入未知 mxn行数据，用空格隔开，读入作为input, 输入为一个矩阵。
int main() {
    vector<vector<int>> result;
    string input;
    while(getline(cin, input)) { // 一行读到input里。
        if (input.size() > 0) { // 如果读到
            stringstream ssin(input); // 将input作为流
            int num; // 类型
            vector<int> path;
            while (ssin >> num) {
                path.push_back(num);
            }
            result.push_back(path);
        }
    }
}
// 当cin读取数据时，会忽略空格、制表符或换行符。所以如果字符串之间有空格，那么cin就会读取结束
// getline可以读取整行，包括前导和空格，并存储在字符串对象中
// string 使用
// 连接字符串
// str = str + "hello";
//****************读取字符串
// 读取一行字符串作为input
int main() {
    string input;
    string res;
    while (getline(cin, input)) {
        if (input.size() > 0) {
            stringstream ssin(input);
            string s;
            while (ssin >> s) {
                res += s;
            }
        }
    }
    cout << res <<endl;
    return 0;
}

// 读取两行行字符串作为input，str1和str2
int main() {
    string str1;
    string str2;
    

}

// 读取一行字符串，每个字符串之间用空格间隔

// 读取一行字符串，每个字符串之间用，分隔

// 读取多行字符串，每个字符串之间用，分隔
