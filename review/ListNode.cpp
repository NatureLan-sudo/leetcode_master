#include "common_include.h"
// 删除链表元素
// 需要考虑头节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = prev;
        while (cur -> next != nullptr ) {
            if (cur -> next -> val ==val) {
                cur-> next = cur -> next -> next;
            } else {
                cur = cur  -> next;
            }
        }
        return prev -> next;
    }
};
// 206 翻转链表
// 示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        // 其实cur 代表的是下一个要处理的节点，prev是处理了的正确的节点，当下一个要处理的变为空了，说明链表结束了
        while (cur) {
            ListNode* temp = cur -> next; 
            cur -> next = prev;          
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};
// 翻转相邻节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    }
};

// 删除链表的倒数第N个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode(0);
        prev -> next = head; // 定义哑节点，方便处理头部。
        ListNode* fast = prev;
        ListNode* slow = prev;
        while (n-- && fast!=nullptr) {
            fast = fast -> next;
        }
        fast = fast -> next; // 多走一步方便取到前一个节点
        while(fast->next!=nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return prev -> next;

    }
};
// 删除链表中的重复元素，保留一个  83
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = head;
        while (cur != nullptr && cur -> next != nullptr) {
            if (cur -> val == cur -> next ->val) {
                cur -> next = cur -> next -> next;
            } else {
                cur = cur -> next;
            }
        }
        return prev -> next;
    }
};

// 删除链表中的重复元素，全部删除  82
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int dead = 0;
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = prev;
        while (cur != nullptr && cur -> next != nullptr && cur -> next -> next != nullptr) {
            if (cur -> next -> val == cur -> next -> next -> val ) {
                dead = cur -> next -> val;
                while (cur -> next != nullptr && cur -> next -> val == dead) {
                    ListNode* temp = cur -> next;
                    cur -> next = cur -> next -> next;
                    delete temp;
                }
            }else {
              cur = cur -> next;
            }
        }
        return prev -> next;

    }
};
// 203 删除链表中指定的元素
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = prev;
        while (cur != nullptr && cur -> next != nullptr) {
            if (cur -> next -> val == val) {
                cur -> next =cur -> next -> next;
            } else {
                cur = cur -> next;
            }
        }
        return prev -> next;
    }
};
// 链表翻转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            // 首先保存下一位
            ListNode* tmp = cur -> next;
            cur -> next = prev;
            prev = cur;  // 移动到当前位
            cur =tmp; // 移动到下一位；                                                             
        }
        return prev;
    }
};
// 交换相邻链表元素
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = prev;
        while (cur -> next != nullptr && cur -> next -> next != nullptr) {
            ListNode* temp = cur -> next;
            ListNode* temp1 = cur -> next -> next -> next;
            cur -> next = cur -> next -> next;
            cur -> next -> next = temp;
            cur -> next -> next -> next = temp1;
            cur = cur -> next -> next;
        }
        return prev -> next;
    }
};