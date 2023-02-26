/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-10 10:58:18
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-22 14:09:06
 * @FilePath: /leet/common_include.h
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#ifndef COMMON_INCLUDE_H
#define COMMON_INCLUDE_H
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <deque>   // 双向队列
#include <queue> // 单向队列
#include <stack> // 栈
#include <memory> //智能指针
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif // COMMON_INCLUDE_H
