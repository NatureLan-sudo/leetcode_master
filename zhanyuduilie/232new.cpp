/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-26 09:14:54
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-26 09:30:29
 * @FilePath: /leet/zhanyuduilie/232new.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include <stack>
#include "common_include.h"
class MyQueue {
public:
    stack<int> stin; // 输入栈
    stack<int> stout; //输出栈
    MyQueue() {

    }
    
    void push(int x) {
        stin.push(x);
    }
    // 弹出队头头并返回队列头的值
    int pop() {
        if (stout.empty()) { // 这里很重要要判断输出栈是空的，空的就说明 还没有进行pop过，或者已经pop完了
            //如果没有pop完，那么stout中仍然能够保证是最前面的数字
            while(!stin.empty()) {
            stout.push(stin.top());
            stin.pop(); 
        }
        }
        int result = stout.top();
        stout.pop();
        return result;
    }
    
    int peek() {
        int result = this -> pop();
        stout.push(result);
        return result;

    }
    
    bool empty() {
        return stin.empty()&&stout.empty();

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */