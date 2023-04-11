/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-22 09:50:31
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-22 22:43:43
 * @FilePath: /test/highpin.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;
// 链表
struct ListNode {
    public:
    int val;
    ListNode* next;
    ListNode();
    ListNode(int val) : val(val), next(nullptr) {};
};
//BM1  
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //处理头结点添加prev,提供末尾的空节点。这个节点不指向头
        ListNode* prev = nullptr;
        ListNode* cur = pHead;
        while (cur!=nullptr) {
            ListNode* tmp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};
// BM2 在区间内反转
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* prev_cur = prev;
        // 取得m前的一个节点
        // prev  1 2 3 4 5    m = 2 n = 4
        //
        ListNode* cur = head;
        int num1 = m - 1;
        while (num1--) {
            prev_cur = cur;
            cur = cur -> next;
        }
        // prev_cur是待反转前的一个节点 cur是操作节点
        int num2 = n -m;
        while (num2 --) {
            // 1324 
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            tmp -> next = prev_cur -> next;
            prev_cur -> next = tmp;
        }
        return prev -> next;
    }
};

// BM3 每k个一组，如果不是k的倍数。剩下的保持原样
// 输入：
// {1,2,3,4,5},2
// 复制
// 返回值：
// {2,1,4,3,5}
// 关键在于K一组循环
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* prev_cur = prev;
        ListNode* cur = head;
        int len = 0;
        while (cur) {
            cur = cur -> next;
            len++;
        }
        cur = head;
        for (int i = k; i <= len; i += k) { // 如果最后不足k就跳出循环不再反转
            int num = k - 1;
            while (num--) {
                ListNode* tmp = cur -> next;
                cur -> next = tmp -> next;
                tmp -> next = prev_cur -> next;
                prev_cur -> next = tmp;
            }
            prev_cur = cur;
            cur = cur -> next;
        }
        return prev -> next;

    }
};
// BM4 合并两个排序链表
// 关键在于要新建一个头
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        while (cur1 && cur2) {
            if (cur1 -> val >= cur2 -> val) {
                cur -> next = cur2;
                cur2 = cur2 -> next;
            } else {
                cur -> next = cur1;
                cur1 = cur1 -> next;
            }
            cur = cur -> next;
        }
        // 如果其中有一个到末尾了，那么就接上另一个
        if (cur1) {
            cur -> next = cur1;
        }
        if (cur2) {
            cur -> next = cur2;
        }
        return head -> next;
    }
};
// BM5 合并k个升序链表

// BM6 判断是否有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* fast = prev;
        ListNode* slow = prev;
        while (fast != nullptr && fast -> next != nullptr&& slow != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) return true;
        } // 有任意一个到0了。
        return false;
    }
};
// BM7 找到入口节点
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* prev = new ListNode(0);
        prev -> next = pHead;
        ListNode* fast = prev;
        ListNode* slow = prev;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                slow = prev; // 要回到prev
                while(fast!=slow) {
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return fast;
            }
        } // 有任意一个到0了。
        return nullptr;
    }
};
// BM8 倒数第N个
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode* prev = new ListNode(0);
        prev -> next = pHead;
        ListNode* fast = prev;
        ListNode* slow = prev;
        while(k-- && fast != nullptr) {
            fast = fast -> next;
        }
        if (fast == nullptr) return nullptr;
        while (fast -> next != nullptr) { // 取得k节点前的那个节点
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow -> next;

    }
};

// BM17
//给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1; // 没找到
    }
};
// BM23 二叉树前序遍历
struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr),right(nullptr) {};
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    void preorder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        // 中左右
        res.push_back(node -> val);
        preorder(node -> left, res);
        preorder(node -> right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        preorder(root, res);
        return res;
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) { // 存在 不为空
                st.pop();
                // 先进后出
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
                st.push(node);
                st.push(nullptr);                
            } else { // 不为空 ，说明是我们标记的中间节点
                st.pop();
                TreeNode* node = st.top();
                st.pop();
                res.push_back(node -> val);
            }
        }
        return res;
    }
}; 
// BM35 是不是完全二叉树
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr) return true;
        que.push(root);
        bool flag = false;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (!node -> left && node -> right) return false;
                if (flag == true && (node -> left ||node -> right)) return false;
                if (!node -> left ||!node -> right ) flag = true;
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
        } 
        return true;
    }
};


//BM 42 两个栈实现队列 队列先进先出
// 用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 
// 队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (!stack2.empty()) {
            int res = stack2.top();
            stack2.pop();
            return res;
        }  // 说明上次反转的还没pop完
        else {
           // stack1倒序进入stack2
           while (!stack1.empty()) {
               int  a = stack1.top();
               stack2.push(a);
               stack1.pop();
           }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

// BM50
// 给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
// 注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> key;
        for (int i = 0; i < numbers.size(); i++) {
            if (key.find(target - numbers[i]) == key.end()) {
                key.insert(make_pair(numbers[i], i + 1));
            } else {
                int val = target - numbers[i];
                return key[val] > i ? vector<int> {i +1, key[val]} : vector<int> {key[val], i + 1};
            }
        }
        return {-1, -1};
    }
};
// BM 55 没有重复数字全排列
// 给出一组数字，返回该组数字的所有排列
// 例如：
// [1,2,3]的所有排列如下
// [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], [3,2,1].
// (以数字在数组中的位置靠前为优先级，按字典序排列输出。）
// 题目没有说明是否有元素重复
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &num, vector<bool> &used) {
        if (path.size() == num.size()){
            res.push_back(path);
            return;
        } 
        // 排列问题从0开始
        for (int i = 0; i < num.size(); i++) {
            // true 是同一树枝重复，false是同一树层重复
            if (i > 0 && num[i] == num[i - 1] && used[i - 1] == false) continue;
            if (used[i] == false) { // 对于本次选择，同一树枝没用过
                used[i] = true;
                path.push_back(num[i]);
                backtracking(num,used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<bool> used(num.size(), false);
        backtracking(num, used);
        return res;
    }
};

// BM83
// 大写到小写 +32  小写到大写 -32
class Solution {
public:
    void reverseStr(string &s, int i, int j) {
        while ( i < j) {
            swap(s[i], s[j]);
            i++; j--;
        }
    }
    string trans(string s, int n) {
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
            } else {
                continue;
            }
        }
        reverseStr(s, 0, n - 1);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] ==' ' ) {
                reverseStr(s, j, i - 1);
                j = i + 1;
            }
            if (i == n - 1) {
                reverseStr(s, j , i);
            }
        }
        return s;
    }
};

// BM97 旋转数组

class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    void reverseVec(vector<int>& a, int i, int j) {
        while(i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        } 
    }
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        // 12345
        // 54321
        // 45123
        m = m % n;
        reverseVec(a, 0 , n - 1);
        reverseVec(a, 0, m - 1);
        reverseVec(a, m, n - 1);
        return a;
    }
};