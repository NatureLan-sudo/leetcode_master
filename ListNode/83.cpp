/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-09-24 22:19:29
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-09-25 10:52:11
 * @FilePath: /leet/ListNode/83.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
// 删除链表中的重复元素
// 链表是排序好的，因此比较简单
#include "common_include.h"
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        prev = prev -> next;
        while (prev != nullptr && prev -> next != nullptr) {
            if(prev->val == prev -> next -> val) {
                prev -> next = prev -> next ->next;
            } else {
                prev = prev ->next;
            }
        }
        return head;  
    }
};
//* 如果链表是无序的，那我们就需要记录下来这个数是不是出现过。在整体比较小的时候，可以用数组，但是如果特别大，储存空间会被浪费的
//* 题目中有负数，所以不能采用数组了

//* 不采用数组，可以使用map，记录元素是不是出现过，也可以实现的。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> key;
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        while (prev != nullptr && prev -> next != nullptr) {
            if (key.find(prev -> next ->val ) != key.end()) {
                prev -> next =prev -> next -> next;
            } else {
                key.insert(make_pair(prev -> next -> val, 0));
                prev = prev -> next;
            }
        }
        return head;
    }
};
// ListNode* prev = new ListNode(0);
// unordered_map<int, int> key;
// if (key.find(prev -> data) != key.end()) {// 说明存在过了
//     prev -> next = prev -> next -> next;
// } else {
//     key.insert(make_pair(prev-> next -> data, 0));
// }
