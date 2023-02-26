#include "common_include.h"
// BM1 
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode* prev = nullptr;
		ListNode* cur = pHead;
		while (cur != nullptr ) {
			ListNode* tmp = cur -> next;
			cur -> next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
    }
};
// BM2 时间复杂度 O(n)，空间复杂度 O(1)。
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
        ListNode* cur = head;
        int num1 = m - 1;
        while (num1--) {
            prev_cur = cur;
            cur = cur -> next;
        }
        int num2 = n - m;
        // 这种局部反转和整体反转的逻辑是不同的
        while(num2--) {
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            tmp -> next = prev_cur -> next;
            prev_cur -> next = tmp;
        }
        return prev -> next;
    }
}; 
// BM3 每k个一组反转
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur -> next;
        }
        cur = head;
        ListNode* prev_cur = prev;
        for (int i = k; i <= len; i += k) {
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


//BM42
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) { // 如果不为空，那么已经存储了早来的元素
            while (!stack1.empty()) {
                int num = stack1.top();
                stack2.push(num);
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

// BM43
// 包含min函数的栈
class Solution {
public:
    void push(int value) {
        que.push_back(value);
    }
    void pop() {
        que.pop_back();   
    }
    int top() {
        return que.back();
    }
    int min() {
        int min = que.front();
        int size = que.size();
        while (size--) {
            min = min < que.front() ? min : que.front();
            que.push_back(que.front());
            que.pop_front();
        }
        return min;
    }
private:
    deque<int> que;
};
// BM44

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        for (auto i : s) {
            if (i == '(') st.push(')');
            else if (i == '{') st.push('}');
            else if (i == '[') st.push(']');
            else if (st.empty() || i != st.top()) return false;
            else st.pop();
        }
        return st.empty();
    }
};
// BM23 前序遍历
class Solution {
public:
    void qianxu(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        res.push_back(node -> val);
        qianxu(node -> left, res);
        qianxu(node -> right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        qianxu(root, res);
        return res;
    }
};
// BM24 中序遍历
class Solution {
public:
    void zhongxu(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        zhongxu(node -> left, res);
        res.push_back(node -> val);
        zhongxu(node -> right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        zhongxu(root, res);
        return res;
    }
};
// BM25 后序遍历
class Solution {
public:
    void houxu(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        houxu(node -> left, res);
        houxu(node -> right, res);
        res.push_back(node -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        houxu(root, res);
        return res;
    }
};

// BM26 层序遍历
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root == nullptr) return res;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node -> val);
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// BM26 按之字形层序打印二叉树
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (pRoot == nullptr) return res;
        que.push(pRoot);
        int i = 1;
        while (!que.empty()) {
            i++;
            int size = que.size();
            vector<int> vec;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node -> val);
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
            if (i%2 != 0) reverse(vec.begin(), vec.end());
            res.push_back(vec);
        }
        return res;
    }
};
// BM28 二叉树的最大深度
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int getdepth(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = getdepth(node -> left);
        int right = getdepth(node -> right);
        int depth = 1 + max(left, right);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        // write code here
        return getdepth(root);
    }
};
// BM29 是否存在某一个值的路径
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    void getsum(TreeNode* node, int num, bool &res, int sum) {
        if (node == nullptr) return;
        sum += node -> val;
        if (node -> left == nullptr && node -> right == nullptr) {
            if (sum == num) {
                res = true; 
                return;
            }
        }
        getsum(node -> left, num, res, sum);
        getsum(node -> right, num, res, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        int num = sum;
        int numsum = 0;
        bool res = false;
        getsum(root, num, res, numsum);
        return res;
    }
};


// BM88 
class Solution {
public:
    bool judge(string str) {
        int left = 0;
        int right = str.length() - 1;
        while (left <= right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};