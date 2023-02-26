/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-02-22 11:45:30
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-02-26 17:20:44
 * @FilePath: /leet/erchashu/review2.cpp
 * @brief: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "common_include.h"
// 前中后递归
// 前中后迭代
// 层次
// 递归
class Solution {
public:
    void qianxu(TreeNode* Node, vector<int> &res) {
        if (Node == nullptr) return;
        res.push_back(Node->val); // 中
        qianxu(Node -> left, res); // 左
        qianxu(Node -> right, res);  // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        qianxu(root, res);
        return res;
    }
};
// 中
class Solution {
public:
    void zhongxu(TreeNode* Node, vector<int> &res) {
        if (Node == nullptr) return;
        zhongxu(Node -> left, res); // 左
        res.push_back(Node->val); // 中
        zhongxu(Node -> right, res);  // 右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        zhongxu(root, res);
        return res;
    }
};
// 后
class Solution {
public:
    void houxu(TreeNode* Node, vector<int> &res) {
        if (Node == nullptr) return;
        houxu(Node -> left, res); // 左
        houxu(Node -> right, res);  // 右
        res.push_back(Node->val); // 中
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        houxu(root, res);
        return res;
    }
};

// mid
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                // 栈先入先出 所以 最后加入左节点
                st.pop();
                if (node -> right) st.push(node -> right);
                st.push(node);
                st.push(nullptr);
                if (node -> left) st.push(node -> left);
            } else {
                st.pop(); // 空节点弹出
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node -> val);
            }
        }
        return result;
    }
};
// front
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                // 栈先入先出 所以 最后加入左节点
                st.pop();
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
                st.push(node);
                st.push(nullptr);
            } else {
                st.pop(); // 空节点弹出
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node -> val);
            }
        }
        return result;
    }
};
// back
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.push(nullptr);
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
            } else {
                st.pop(); // 空节点弹出
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node -> val);
            }
        }
        return result;
    }
};
// cengxu 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            vector<int> vec;
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node -> val);
                if (node -> left) que.push(node ->left);
                if (node -> right) que.push(node -> right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// reverse
// 前序 好理解
class Solution {
public:
    void reverse(TreeNode* node) {
        // 前序
        if (node == nullptr) return;
        swap(node -> left, node -> right); // 中
        reverse(node -> left);  // 左
        reverse(node -> right);  //右
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* head = root;
        reverse(root);
        return head;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        invertTree(root -> left);
        invertTree(root -> right);
        swap (root -> left, root -> right);
        return root;
    }
};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

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
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* prev = new ListNode();
        ListNode* fast = prev;
        ListNode* slow = prev;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next ->next;
            slow = slow -> next;
            if (fast == slow) {
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
// 检查是否为对称
// 递归方法
class Solution {
public:
    bool compare(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode != nullptr) return false;
        else if (leftNode != nullptr && rightNode == nullptr) return false;
        else if (leftNode == nullptr && rightNode == nullptr) return true;
        else if (leftNode -> val != rightNode -> val) return false;
        else { // 两个节点都不为空的时候且内容相等的时候。
            bool out = compare(leftNode -> left, rightNode -> right);
            bool in = compare(leftNode -> right, rightNode -> left);
            return out && in;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root -> left, root -> right);
    }
};
// 迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root -> left);
        que.push(root -> right);
        while (!que.empty()) { // 判断两棵树是否翻转
            TreeNode* LeftNode = que.front();
            que.pop();
            TreeNode* RigtNode = que.front();
            que.pop();
            // 判断逻辑
            if (LeftNode == nullptr && RigtNode != nullptr) return false;
            else if (LeftNode != nullptr && RigtNode == nullptr) return false;
            else if (LeftNode == nullptr && RigtNode == nullptr) continue;
            else if (LeftNode -> val != RigtNode -> val) return false;
            que.pop();
            TreeNode* RigtNode = que.front();
            que.pop();
            // 判断逻辑
            if (LeftNode == nullptr && RigtNode != nullptr) return false;
            else if (LeftNode != nullptr && RigtNode == nullptr) return false;
            else if (LeftNode == nullptr && RigtNode == nullptr) continue;
            else if (LeftNode -> val != RigtNode -> val) return false;
            
            que.push(LeftNode -> left);
            que.push(RigtNode -> right);
            que.push(LeftNode -> right);
            que.push(RigtNode -> left);
        }
        return true;
    }
};


// 最大深度
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。
class Solution {
public:
    int getdepth(TreeNode* Node) {
        if (Node == nullptr) return 0;
        int left = getdepth(Node -> left);
        int right = getdepth(Node -> right);
        int depth = left > right ? left + 1 : right + 1;  // 判断左边大还是右边大，用大的，然后再加上这层根节点的。
        return depth;

    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return getdepth(root);
    }
};
// 利用层序遍历实现求取最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
            depth += 1;
        }
        return depth;
    }
};
// 最小深度
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 只有左右孩都为空才到达了最低点
class Solution {
public:
    int GetMinDepth (TreeNode* node) {
        if (node == nullptr) return 0;
        int left = GetMinDepth(node -> left);
        int right = GetMinDepth(node -> right);
        if (node -> left == nullptr && node -> right != nullptr) return 1 + right;
        if (node -> left != nullptr && node -> right == nullptr) return 1 + left;
        int depth = 1 + min(left, right);
        return depth;

    }
    int minDepth(TreeNode* root) {
        return GetMinDepth(root);
    }
};
// 迭代法 层序遍历得到最小深度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            depth += 1;
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
                if (!node -> right && !node -> left)return depth;  // 这个节点的左右孩子都不存在
            }
        }
        return depth;
    }
};

// 完全二叉树的节点个数
// 不利用完全二叉树性质的话，直接遍历就行了。
// 深度为h的二叉树 ，满树由2^h - 1 个节点
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层
// 则该层包含 1~ 2h 个节点。
// 迭代到某个节点，成为满二叉树，计算深度。 如何判断是否是满二叉树？ 左右深度一致

class Solution {
public:
    int GetNodes(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftdepth = 0;
        int rightdepth = 0;
        TreeNode* left = node;
        while (left) {
            left = left -> left;
            leftdepth++;
        }
        TreeNode* right = node;
        while (right) {
            right = right -> right;
            rightdepth++;
        }
        if (rightdepth == leftdepth) {
            // 2的n次方 , 2 << (n - 1)  注意这里我们是从根节点开始，所以就是n-1
            return (2<<(leftdepth - 1)) - 1;
        }
        // 不相等说明不是满二叉树，继续向下。 左边和右边加起来，再加上中间节点的
        return GetNodes(node -> left) + GetNodes(node -> right) + 1;
    }
    int countNodes(TreeNode* root) {
        return GetNodes(root);
    }
};

// 平衡二叉树
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
// 自底向上递归
class Solution {
public:
    int getdepth(TreeNode* node) {
        if (node == nullptr)  return 0;
        int left = getdepth(node -> left);
        if (left == -1) return -1;
        int right = getdepth(node -> right);
        if (right == -1) return -1;
        return abs(right - left) > 1 ? -1 : 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return getdepth(root) == -1 ? false : true;
    }
};

// 二叉树的所有路径， 需要体现回溯
// 中间符号 -> 的处理
class Solution {
public:
    void binary(TreeNode* node, vector<string>& res, string path) {
        path += to_string(node -> val);  // 地址更新
        if (node -> left == nullptr && node -> right == nullptr) {
            // 说明到叶子节点了。
            res.push_back(path);
            return;
        }
        if (node -> left) binary(node -> left, res, path + "->"); // 要判断是否存在
        if (node -> right) binary(node -> right, res, path + "->");

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr) return result;
        binary(root, result, path);
        return result;
    }
};

// 左叶子之和.左树左叶子，右树右叶子
// 递归
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0;
        if (root -> left != nullptr && root -> left -> left == nullptr && root -> left -> right == nullptr) {
            left = root -> left -> val;
        }
        return left + sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
    }
};
//迭代
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == nullptr) return 0;
        int sum = 0;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node -> left != nullptr && !node -> left -> left && !node -> left -> right) {
                sum += node -> left -> val;
            }
            if (node -> left) st.push(node -> left);
            if (node -> right) st.push(node -> right);
        }
        return sum;
    }
};

// 树左下角的值
// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
// 假设二叉树中至少有一个节点。
// 迭代层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<int> res;
        while (!que.empty()) {
            res.clear();
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                res.push_back(node -> val);
                que.pop();
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
        }
        return res[0];

    }
};
//递归
// 深度大，是左边的，并且是叶子节点
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

    }
};


// 路径总和
class Solution {
public:
    bool travel(TreeNode* cur, int count) {        
        if (!cur -> left && !cur -> right && count == 0) return true;
        if (!cur -> left && !cur -> right) return false;
        if (cur -> left) {
            count -= cur -> left -> val;
            if (travel(cur -> left, count)) return true;
            count += cur -> left -> val; // 撤销处理结果
        } 
        if (cur -> right) {
            count -= cur -> right -> val;
            if (travel(cur -> right, count)) return true;
            count += cur -> right -> val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return travel(root, targetSum - root -> val);
    }
};

class Solution {
public:
    void haspath(TreeNode* node, bool& res, int target, int sum) {
        // 以下过程只要有一次res变成true，就成了。因为程序里没有其他地方改变res的值
        if (node == nullptr) return;
        sum += node -> val; // 更新sum
        if (node -> left == nullptr && node -> right == nullptr) { // 到叶子节点了
            if (sum == target) {
                res = true; 
                return;
            }
        } // 如果存在 就不再执行。
        if (!res) haspath(node -> left, res, target, sum);
        if (!res) haspath(node -> right, res, target, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        int sum = 0;
        haspath(root, res, targetSum, sum);
        return res;
    }
};

// 中后
class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};
// 中后
class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;
        // 后序最后一个元素
        int cur = postorder[postorder.size() - 1];
        TreeNode* node = new TreeNode(cur);
        
        // 如果是叶子节点，不用分割了
        if (postorder.size() == 1) return node;

        // 如果不是叶子节点，那么，下面还有其他元素，所以要根据这个元素找到中序的分割点
        int fengedian = 0;
        for (fengedian = 0; fengedian < inorder.size(); fengedian++) {
            if (inorder[fengedian] == cur) break;
        }

        // 分割中序
        // 左： [0, 分割点] 右：[分割点+1, end]
        vector<int> left_inorder(inorder.begin(), inorder.begin() + fengedian);
        vector<int> right_inorder(inorder.begin() + fengedian + 1, inorder.end());

        // 后序舍去尾部
        postorder.resize(postorder.size() - 1);
        // 分割后序列
        vector<int> left_postoder(postorder.begin(), postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end());

        node -> left = traversal(left_inorder, left_postoder);
        node -> right = traversal(right_inorder, right_postorder);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};

// 中前
class Solution {
public:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        // 用引用效率更高
        if (preorder.size() == 0) return nullptr;

        int cur = preorder[0];
        TreeNode* cur_node = new TreeNode(cur);
        
        // 只有一个数说明是根节点，不用分割
        if (preorder.size() == 1) return cur_node;

        // 不是根节点，分割
        int fengedian = 0;
        for (fengedian = 0; fengedian < inorder.size(); fengedian++) {
            if (inorder[fengedian] == cur) break;
        }
        
        // 分割中序  左闭右开
        vector<int> left_inorder(inorder.begin(), inorder.begin() + fengedian);
        vector<int> right_inorder(inorder.begin() + fengedian + 1, inorder.end());

        // 前序剔除头部元素  左闭右开
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());

        cur_node -> left = traversal(left_preorder, left_inorder);
        cur_node -> right = traversal(right_preorder, right_inorder);
        return cur_node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return traversal(preorder, inorder);
    }
};

