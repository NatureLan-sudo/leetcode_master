#include "common_include.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 迭代的统一方法， 基于NULL标记，标记的是已经访问了但是处理的节点，也就是都是中间节点
// 前序
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop(); // 因为这个点是中间节点，所以我们先把他删了，用于换成我们想要的顺序
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node -> left);
                st.push(node);
                st.push(nullptr);
            } else {
                st.pop(); // 先把空指针弹出去
                node = st.top();
                st.pop(); 
                res.push_back(node -> val);
            }
        }
        return res;
    }
};
// 中序 // 统一的方法用NULL 标记了所有中间的节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop(); // 因为这个点是中间节点，所以我们先把他删了，用于换成我们想要的顺序
                if (node -> right) st.push(node -> right); // 先进后出  右孩
                st.push(node);                                //  中
                st.push(nullptr);
                if (node -> left) st.push(node -> left); //左
            } else {
                st.pop(); // 先把空指针弹出去
                node = st.top();
                st.pop(); 
                res.push_back(node -> val);
            }
        }
        return res;
    }
};
// 后序 左右中
// 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop(); // 因为这个点是中间节点，所以我们先把他删了，用于换成我们想要的顺序
                st.push(node);                                //  中
                st.push(nullptr);
                if (node -> right) st.push(node -> right); // 先进后出  右孩
                if (node -> left) st.push(node -> left); //左
            } else {
                st.pop(); // 先把空指针弹出去
                node = st.top();
                st.pop(); 
                res.push_back(node -> val);
            }
        }
        return res;
    }
};


// 不统一的中序需要把赋值和压栈分开，后序在前序基础上改进
// 不统一的回顾
// 前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    // 前序
    stack<TreeNode*> st;
    vector<int> res;
    if (root == nullptr) return res;
    st.push(root);
    while (!st.empty()) { //如果为空了说明节点遍历完了
        TreeNode* cur = st.top();
        st.pop();
        res.push_back(cur -> val);
        if (cur -> right) st.push(cur -> right); // 后出先进
        if (cur -> left) st.push(cur -> left);
    }
    return res;
    }
};
// 中序遍历
class Solution {   
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        //中序与众不同
        if (root == nullptr)  return res;
        // 第一个根节点放进去
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
              //说明还没到最后一层左节点
              st.push(cur);
              cur =cur ->left; //继续找左孩子 左 
            } else {
                cur = st.top();
                st.pop();
                res.push_back(cur -> val);  //中
                cur = cur -> right;
            }
        }
        return res;
    }
};
// 后序 左右中  中右左倒过来
class Solution {   
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) return res;
        st.push(root);
     while (!st.empty()) { //如果为空了说明节点遍历完了
        TreeNode* cur = st.top();
        st.pop();
        res.push_back(cur -> val);
        if (cur -> left) st.push(cur -> left);   // 后出先进
        if (cur -> right) st.push(cur -> right); 
        }
        reverse(res.begin(),res.end());
        return res;  
    }
};
