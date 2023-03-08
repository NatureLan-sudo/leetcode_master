/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-08 17:05:58
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-08 22:20:22
 * @FilePath: /test/huisu/Nqueen.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h" 
// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
// n 皇后， 放置 nxn 棋盘
class Solution {
public:
    vector<vector<string>> result;
    // 不能同行， 不能同列，不能同斜线
    bool isValid(int row, int col, vector<string> &path, int n) {
        // 不能同列,因为我们是向下深度递归，所以不会出现同行
        for (int i = 0; i < row; i++) { // row以下的还没迭代到的，都是.
            if (path[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0;  i--, j--) { // 左斜上，右斜上
            if (path[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (path[i][j] == 'Q') return false;
        }
        return true;

    }
    void backtracking(int n, int row, vector<string> &path) {
        if (row == n) { // 行数也是高度
            result.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {// 棋盘宽度是for循环长度
            if (isValid(row, col, path, n)) {
                path[row][col] = 'Q';
                backtracking(n, row + 1, path);
                path[row][col] = '.';
            } 
        // 递归深度是棋盘高度
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, std::string(n,'.'));
        backtracking(n, 0, path);
        return result;
    }
};