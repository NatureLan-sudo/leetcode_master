/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-07-10 20:19:16
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-07-11 21:40:36
 * @FilePath: /leetcode_master/gaopin/niukegaopin.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
// 一天10题。
#include "common_include.h"
//BM1
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
  public:
    ListNode* ReverseList(ListNode* pHead) {
        //处理头结点添加prev,提供末尾的空节点。这个节点不指向头
        ListNode* prev = nullptr;
        ListNode* cur = pHead;
        while (cur != nullptr) {
            ListNode* tmp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};

//BM2
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

// BM3
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
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        ListNode* prev = new ListNode(0);
        ListNode* prev_cur = prev;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1 -> val >= pHead2 -> val) {
                prev -> next = pHead2;
                pHead2 = pHead2 -> next;
            } else {
                prev -> next = pHead1;
                pHead1 = pHead1 -> next;
            }
            prev = prev -> next;   
        }
        if (pHead2 != nullptr) {
            prev -> next = pHead2;
        } else {
             prev -> next = pHead1;
        }
        return prev_cur -> next;
    }
};

//* BM5 合并 k 个升序的链表并将结果作为一个升序的链表返回其头节点。归并分治。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergetwo(ListNode* phead1, ListNode* phead2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (phead1 != nullptr && phead2 != nullptr) {
            if (phead1 -> val <= phead2 -> val) {
                head -> next = phead1;
                phead1 = phead1 -> next;
            } else {
                head -> next = phead2;
                phead2 = phead2 -> next;           
            }
            head = head -> next;
        }
        if (phead2 == nullptr) {
            head -> next = phead1;
        } else {
            head -> next = phead2;
        }
        return cur -> next;
    }
    ListNode* dividetwo(vector<ListNode *> &lists, int left, int right) {
        int mid = (right - left) /2 + left;
        if (left > right) return nullptr;
        else if (left == right) {
            return lists[left];
        } else {
            return mergetwo(dividetwo(lists, left, mid), dividetwo(lists, mid + 1, right));
        }

    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return dividetwo(lists, 0 , lists.size() - 1);
    }
};

//* BM6 判断链表是否有环
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

//* BM7 链表环的入口结点。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                fast = pHead;
                while (fast != slow) {
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

//* BM8 链表的倒数第K个节点
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
     如果该链表长度小于k，请返回一个长度为 0 的链表。
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        ListNode* prev = new ListNode(0);
        prev -> next = pHead;
        ListNode* fast = prev;
        ListNode* slow = prev;
        while (k-- && fast != nullptr) {
            fast = fast -> next;
        }
        if (fast == nullptr) return nullptr;
        while (fast != nullptr) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};

//* BM9 删除链表的倒数第N个节点
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code her e
        ListNode* fast = new ListNode(0);
        fast -> next = head;
        ListNode* slow = fast;
        ListNode* prev = fast;
        while (n --) {
            fast = fast -> next;
        }
        while (fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return prev -> next; 
    }
};

//* BM10 链表的第一个公共结点
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0;
        int len2 = 0;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        while (cur1 != nullptr) {
            cur1 = cur1 -> next;
            len1 ++;
        }
        while (cur2 != nullptr) {
            cur2 = cur2 -> next;
            len2 ++;
        }
        if (len1 < len2) {
            swap(pHead1, pHead2);
            swap(len1, len2);
        } // 保证pHead1是长的.
        cur1 = pHead1;
        cur2 = pHead2;
        // 尾部对齐
        int num = len1 -len2;
        while (num --) {
            cur1 = cur1 -> next;
        }
        while (cur1 != nullptr) {
            if (cur1 == cur2) return cur1;
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        return nullptr;
    }
};

//* BM11 链表相加
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// 1 链表长度需要对齐,也是尾端对齐
// 2 相加后可能需要进位
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* tmp = head -> next;
            head -> next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }

    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;
        ListNode* phead1 = reverseList(head1);
        ListNode* phead2 = reverseList(head2);
        ListNode* phead3 = new ListNode(0);
        ListNode* nhead = phead3;
        int jinwei_last = 0;
        while (phead1 != nullptr || phead2 != nullptr) {
            int jinwei_new = jinwei_last;
            if (phead1 != nullptr) {
                jinwei_new += phead1 -> val;
                phead1 = phead1 -> next;
            }
            if (phead2 != nullptr) {
                jinwei_new += phead2 -> val;
                phead2 = phead2 -> next;
            }
            jinwei_last = jinwei_new/10; // 进位值
            nhead -> next = new ListNode(jinwei_new%10);
            nhead = nhead -> next;
        }
        // 最后一位
        if (jinwei_last!= 0) {
            nhead -> next = new ListNode(jinwei_last);
        }
        return reverseList(phead3 -> next);
    }
};

//* BM12 单链表排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        // 先分割,再对比合并,先递归分割到最小单元
        // 递归终止条件
        if (head == nullptr || head -> next == nullptr) return head;

        // 循环体是二分
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* mid = slow -> next ;
        slow -> next = nullptr;

        ListNode* phead1 = sortInList(head);
        ListNode* phead2 = sortInList(mid);
        
        // 结果操作单元是合并
        ListNode* phead = new ListNode(0);
        ListNode* nphead = phead;
        while (phead1 != nullptr && phead2 != nullptr) {
            if (phead1 -> val < phead2 -> val) {
                phead -> next = phead1;
                phead1 = phead1 -> next;
            } else {
                phead -> next = phead2;
                phead2 = phead2 -> next;
            }
            phead = phead -> next;
        }
        if (phead1 == nullptr) {
            phead -> next = phead2;
        } else{
            phead -> next = phead1;
        }
        return nphead -> next;
    }
};

//* BM13 判断链表是否回文
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here  
        // 找中点,反转,然后对比.
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* phead = slow -> next;
        slow -> next = nullptr;
        ListNode* prev = nullptr;
        while (phead != nullptr) {
            ListNode* tmp = phead -> next;
            phead -> next = prev;
            prev = phead;
            phead = tmp;
        }
        while (prev != nullptr && head != nullptr) {
            if (prev -> val != head -> val) return false;
            prev = prev -> next;
            head = head -> next;
        }
        return true;
    }
};

//* BM14 链表奇数节点和偶数节点重排
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        if (head == nullptr) return nullptr;
        ListNode* jishu = head;
        ListNode* oushu = head -> next;
        ListNode* oushuhead = oushu;
        // 偶数一定在奇数后面,所以判断偶数
        while (oushu != nullptr && oushu -> next != nullptr) {
            jishu -> next = oushu -> next;
            jishu = jishu -> next;
            oushu -> next = jishu -> next;
            oushu = oushu -> next;
        }
        jishu -> next = oushuhead;
        return head;
    }
};

//*BM15  删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        while (head != nullptr && head -> next != nullptr) {
            if (head -> val == head -> next -> val) {
                head -> next = head -> next -> next;
            } else {
                head = head -> next;
            }
        }
        return prev -> next;
    }
};

//*BM16 删除所有重复元素,也就是说,该元素只要重复就删掉
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* cur = head;
        ListNode* prev_cur = prev;
        while (cur != nullptr  && cur -> next != nullptr) {
            if (cur -> val == cur -> next -> val) {
                int tmp = cur -> val; // 这里要给定值,不然可能会出现相邻元素重复但不是同一个值.
                while (cur != nullptr && cur -> next != nullptr &&  cur -> next -> val == tmp) {
                    cur = cur -> next;
                }
                prev_cur -> next = cur -> next;
                cur = cur -> next;
            } else {
                cur = cur -> next;
                prev_cur = prev_cur -> next;
            }
        }
        return prev -> next;
    }
};

//* BM17 二分查找
// 给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1

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
        // write code here
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target) {
                right = mid - 1; // 记得要变
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

//* BM18 二维数组查找
// 在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
// [
// [1,2,8,9],
// [2,4,9,12],
// [4,7,10,13],
// [6,8,11,15]
// ]
// 给定 target = 7，返回 true。
// 给定 target = 3，返回 false。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param target int整型 
     * @param array int整型vector<vector<>> 
     * @return bool布尔型
     */
    bool Find(int target, vector<vector<int> >& array) {
        // write code here
        if (array.empty()) return false;
        for (auto i : array) {
            if (i.empty()) continue;
            if (target < i[0] || target > i[i.size() -1]) continue;
            int left = 0;
            int right = i.size() - 1;
            while (left <= right) {
                int mid = (right - left) / 2 + left;
                if (i[mid] > target) {
                    right = mid - 1;
                } else if (i[mid] < target) {
                    left = mid + 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

//* BM19 
// 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
// 1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
// 2.假设 nums[-1] = nums[n] = -\infty−∞
// 3.对于所有有效的 i 都有 nums[i] != nums[i + 1]
// 4.你可以使用O(logN)的时间复杂度实现此问题吗？
// 说明不能顺序,这个复杂度得使用二分, 只要返回一个峰值就行,那么我们就保证
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        // write code here
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            // 最后两个值相等的时候一定是波峰
            int mid = (right - left) / 2 + left;
            if (nums[mid]  > nums[mid + 1]) {
                right = mid;   // 下降,右侧可能没有波峰,但是当前可能是波峰,所以不+1
            } else { // 上升, 右侧可能存在波峰的区间,也说明当前mid肯定不是波峰,所以 要+1 
                left = mid + 1; 
            }
        }
        return right;
    }
};

//* BM23 二叉树前序遍历
// struct TreeNode {
// int val;
//     struct TreeNode *left;
//  	struct TreeNode *right;
//  	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    // 中前后
    void qianxu(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        res.push_back(node -> val);
        qianxu(node -> left, res);
        qianxu(node -> right, res);            
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        vector<int> res;
        qianxu(root , res);
        return res;
    }
};
// 顺序遍历用栈
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    // 中前后
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr)  return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop(); // 栈,后进先出,按照中左右顺序.
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
                st.push(node);
                st.push(nullptr); // 标记已经使用过
            } else {
                st.pop();
                TreeNode* node = st.top();
                res.push_back(node -> val);
                st.pop();
            }
        }
        return res;
    }
};

//* BM24 中序遍历
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
     * @return int整型vector
     */
    void zhongxu(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        zhongxu(node -> left, res);
        res.push_back(node -> val);
        zhongxu(node -> right, res);            
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        vector<int> res;
        zhongxu(root, res);
        return res;
    }
};

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
     * @return int整型vector
     */
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr)  return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop(); // 栈,后进先出,按照中左右顺序.
                if (node -> right) st.push(node -> right);
                st.push(node);
                st.push(nullptr); // 标记已经使用过
                if (node -> left) st.push(node -> left);
            } else {
                st.pop();
                TreeNode* node = st.top();
                res.push_back(node -> val);
                st.pop();
            }
        }
        return res;
    }
};

//* BM25 后序遍历
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
     * @return int整型vector
     */
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr)  return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop(); // 栈,后进先出,按照中左右顺序.
                st.push(node);
                st.push(nullptr); // 标记已经使用过
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
            } else {
                st.pop();
                TreeNode* node = st.top();
                res.push_back(node -> val);
                st.pop();
            }
        }
        return res;
    }
};

//*BM26 二叉树层序遍历
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
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                vec.push_back(node -> val);
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
                que.pop();
            }
            res.push_back(vec);
        }
        return res;
    }
};