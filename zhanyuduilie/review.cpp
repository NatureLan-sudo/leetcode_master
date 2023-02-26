/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-21 19:54:53
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-22 11:42:00
 * @FilePath: /leet/zhanyuduilie/review.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "common_include.h"
// 利用栈实现队列
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

class MyQueue {
public:
    // 队列先进先出 栈先进后出
    stack<int> stin;
    stack<int> stout; 
    MyQueue() {

    }
    
    void push(int x) {
        stin.push(x);
    }
    
    int pop() {
        if (stout.empty()) {
            while (!stin.empty()) {
                stout.push(stin.top());
                stin.pop();
            }
        } 
        int out = stout.top();
        stout.pop();
        return out;
    }
    
    int peek() {
       int res = this -> pop();
       stout.push(res);
       return res;
    }
    
    bool empty() {
        return stout.empty() && stin.empty();
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
// 利用队列实现栈
// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size() - 1;
        while (size --) {
            int a = q1.front();
            q2.push(a);
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while (!q2.empty()) {
            int a = q2.front();
            q1.push(a);
            q2.pop();
        }
        return res;
    }
    
    int top() {
        int res = this -> pop();
        q1.push(res);
        return res;
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

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        for (auto i : s) {
           // 都是左边
           if (i =='(') st.push(')');
           else if (i == '{') st.push('}');
           else if (i == '[') st.push(']');
           else if (st.empty() || i != st.top()) return false;
           else st.pop();
        }
        return st.empty();
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto i : s) {
            if (st.empty()) {
                st.push(i);
            } else {
                if (st.top() == i) {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        string a;
        while (!st.empty()) {
            a += st.top();
            st.pop();
        }
        reverse(a.begin(), a.end());
        return a;
    }
};
// 需要注意运算顺序
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res;
        for (auto i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i== "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (i == "+") st.push(a + b);
                else if (i == "-")  st.push(b - a);
                else if (i == "*")  st.push(a * b);
                else st.push(b / a);
            } else {
                st.push(std::stoi(i));
            }
        }
        return st.top();
    }
};

// 隐藏了一个潜在的顺序关系
class Solution {
private:
    deque<int> que;
    void pop(int value) { // 当最大值要离开了
        if (!que.empty() && value == que.front()) {
            que.pop_front();
        }
    }
    void push(int value) {  // 有可能成为最值,因为在后面出现
        while (!que.empty() && value > que.back()) {
            que.pop_back();
        }
        que.push_back(value);
    }

    int front() { // 返回最前面的数值
        return que.front();
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Solution que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);  // 移除前面的元素
            que.push(nums[i]);     // 加入后进来的元素，看看是不是最大值咯、
            result.push_back(que.front());
        }
        return result;

    }
};
//单调递增，尾部是最小值
class Solution {
private:
    deque<int> que;
    void pop(int value) { // 当最大值要离开了
        if (!que.empty() && value == que.front()) {
            que.pop_front();
        }
    }
    void push(int value) {  // 有可能成为最值,因为在后面出现
        while (!que.empty() && value < que.back()) { // 只需要改这个地方
            que.pop_back();
        }
        que.push_back(value);
    }

    int front() { // 返回最前面的数值
        return que.front();
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Solution que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);  // 移除前面的元素
            que.push(nums[i]);     // 加入后进来的元素，看看是不是最大值咯、
            result.push_back(que.front());
        }
        return result;

    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    }
};