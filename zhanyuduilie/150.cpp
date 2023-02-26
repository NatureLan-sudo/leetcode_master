/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-28 13:53:04
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-09 17:52:58
 * @FilePath: /leet/zhanyuduilie/150.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
#include <stack> 
//根据 逆波兰表示法，求表达式的值。
//有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
// 为什么可以用栈，为什么不用队列：因为我们每次处理的是最新的数据，我们希望把最新的数据做完运算之后就变成一个值存起来
// 和消除相邻元素一样，有点像对对碰
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> eval;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" ||tokens[i] == "-" || tokens[i] == "*"||tokens[i] == "/" ) {
                int num1 = eval.top();
                eval.pop();
                int num2 = eval.top();
                eval.pop();
                if (tokens[i] == "+") num2 += num1;
                if (tokens[i] == "-") num2 -= num1;
                if (tokens[i] == "*") num2 *= num1;
                if (tokens[i] == "/") num2 /= num1;
                eval.push(num2);
            } else {
                eval.push(stoi(tokens[i]));
            }
        }
        ans = eval.top();
        eval.pop();
        return ans;
    }
};
// 又给我整乘法运算溢出这一出，用long替代，不过就得直接push了
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(num2+num1);
                if(tokens[i]=="-") st.push(num2-num1);
                if(tokens[i]=="*") st.push((long)num2*(long)num1);
                if(tokens[i]=="/") st.push(num2/num1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
