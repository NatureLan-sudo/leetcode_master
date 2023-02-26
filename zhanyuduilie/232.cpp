/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-25 16:10:25
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-26 09:12:40
 * @FilePath: /leet/zhanyuduilie/232.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include <stack>
#include "common_include.h"
// 使用栈实现队列
// 栈是后入先出，队列是后入后出，加入的元素是加入到队列的尾部
class MyQueue {
public:
    stack<int> stin; // 输入栈
    stack<int> stout;  // 输出栈
    MyQueue() {

    }
    // 向队列的末尾加入元素
    void push(int x) {
        stin.push(x);
    }
    
    int pop() {
        if (stout.empty()) {
            while (!stin.empty()) {// 将输入栈的都导入到输出栈中
            stout.push(stin.top()); // 向输出栈压如输入站的栈顶，相当与后进来的先进去了
            stin.pop(); //弹出栈顶元素
            }
        }
        int result = stout.top();// 相当于队列的末尾
        stout.pop();//去除最后进来的
        return result;
    }
    //获得最前面的元素
    int peek() {
        int result = this -> pop();
        stout.push(result);
        return  result;
    }
    
    bool empty() {
        return (stin.empty()&&stout.empty());

    }
};
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
// 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */