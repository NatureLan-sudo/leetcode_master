#include "common_include.h"
// shanchu daoshu di N ge jiedian 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 这里必须设置哑结点，不然无法处理与头结点有关的问题。
        ListNode* prev = new ListNode();
        prev -> next = head;
        ListNode* left = prev;
        ListNode* right = prev;
        while (n-- && right != nullptr) {
            right = right -> next;
        }
       while (right -> next != nullptr) {
        right = right -> next;
        left = left -> next;
       }
       left -> next = left -> next -> next;
       return prev -> next;
    }
};

// 两两交换链表节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 这种题目就是要注意画图
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* res = prev;
        while (prev -> next != nullptr && prev -> next -> next != nullptr) {
            ListNode* cur = prev -> next;
            ListNode* tmp = cur -> next;
            prev -> next = tmp;
            ListNode* tmp2 = tmp -> next;
            tmp -> next = cur;
            cur -> next = tmp2;
            prev = prev -> next -> next;
        }
        return res -> next;
    }
};

// 链表相交
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
// 这题目是有隐藏条件的，如果相交，那么从尾部开始一定是重合的。利用长度，将尾部进行对齐，然后一一比较，需要注意这里是节点一致而不是节点的值一致
// 注意保证链表的原始结构
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != nullptr) {
            lenA++;
            curA = curA -> next;
        } // 链表A长度
        while (curB != nullptr) {
            lenB++;
            curB = curB -> next;
        } // 链表B长度
        // A 为更长的链表
        curA = headA;
        curB = headB;
       if (lenA < lenB) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while (gap--) {
            curA = curA -> next;
        }
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA -> next;
            curB = curB -> next;
        }
        return nullptr;
    }
};
// 环形链表
//  给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// step1  通过快慢指针确定有没有环
// step2  fast 不变 slow 从头走，再次相遇就是第一节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* prev = new ListNode();
        prev -> next = head;
        ListNode* slow = prev;
        ListNode* fast = prev;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                slow = prev;
                while (slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};