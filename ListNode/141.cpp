/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-25 10:54:17
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-25 11:09:19
 * @FilePath: /leet/ListNode/141.cpp
 * @brief: 判断环形链表
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
#include "common_include.h"
// 判断链表是否出现环

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = new ListNode(0);
        ListNode* fast = new ListNode(0);
        slow -> next = head;
        fast -> next = head;
        while (fast != nullptr && fast -> next != nullptr ) { // 居然判断条件的顺序也会有影响！要先判断fast不为空，如果先判断fast->next就会出错
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
    }
};