/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-26 09:32:05
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-26 10:21:39
 * @FilePath: /leet/zhanyuduilie/225.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include <stack>
#include <queue> // 队列
#include <deque> // 双向队列
#include "common_include.h"
// 队列和栈
class MyStack {
public:
    deque<int> dest; // 双向队列
    MyStack() {

    }
    // 使用双向队列实现
    void push(int x) {
        dest.push_back(x); // 队列末尾加入元素
    }
    
    int pop() {
        int res = dest.back(); //取到队列末尾的元素
        dest.pop_back();  //删除队列末尾的元素
        return res;
    }
    
    int top() {
        int res = this -> pop(); // 调用类内函数实现删除末尾元素并取出末尾元素，这个元素是最后进来的，是栈顶
        dest.push_back(res);
        return res;
    }
    
    bool empty() {
        return dest.empty();

    }
};
// 使用单向队列实现
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }
    void push(int x) {
        q1.push(x); // 队列末尾加入元素
    }
    
    int pop() {  // 将最后进去的先弹出去，并返回这个弹出去的值
        int res = q1.back();
        q2 = q1;
        // q1置位为空
        while (!q1.empty()) {
            q1.pop();
        }
        int size = q2.size()-1; // 留下最后一个元素
        while (size--) {
            q1.push(q2.front()); // 将最旧的元素加入
            q2.pop();       // 将最旧的元素删除
        }
        q2.pop();//q2清空
        return res;
    }
    
    int top() {
        return q1.back(); // 返回最新的元素
    }
    
    bool empty() {
        return q1.empty();

    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */