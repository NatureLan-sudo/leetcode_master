/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-08 17:06:17
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-08 22:49:06
 * @FilePath: /test/huisu/shudu.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include "common_include.h"
// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

class Solution {
public:
    vector<vector<char>> result;
    bool isValid(int row, int col, char k, vector<vector<char>> &board) {
        // 同行
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == k) return false;
        }
        // 同列
        for (int j = 0; j < board.size(); j++) {
            if (board[j][col] == k) return false;
        }
        // 同 3x3
        int startrow = (row / 3) * 3; // 从哪个地方开始。例如7. 7/3 = 2； 2*3=6； 说明是从第六个开始的
        int startcol = (col / 3) * 3;
        for (int i = startrow; i < startrow + 3; i++) {
            for (int j = startcol; j < startcol + 3; j++) {
                if (board[i][j] == k) return false;
            }
        }
        // else
        return true;
    }
    bool backtracking(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) { // 遍历行
            for (int j = 0; j < board[0].size(); j++) { // 遍历列
                if (board[i][j] != '.') continue; // 原数组有填数字
                for (char k = '1'; k <= '9'; k++) { // 1 - 9遍历，看是否符合条件
                    if (isValid(i, j, k,board)) {
                        board[i][j] = k;
                        if (backtracking(board)) return true; // 填完，合适，返回
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};