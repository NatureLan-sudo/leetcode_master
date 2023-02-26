#include "common_include.h"
// 比递归的效率强了很多
// 前序和后序比较简单，后序在前序的基础上变换顺序即可，但是中序需要改变思路
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 前序
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        vector<int> res;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) { // 当栈不为空继续
            TreeNode* head = st.top();
            st.pop();
            res.push_back(head -> val); // 中 只留下栈顶进行赋值
            if (head -> right) st.push(head -> right); // 右
            if (head -> left) st.push(head -> left);  // 左
        }
        return res;

    }
};
// 中序 左中右
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        vector<int> res;
        TreeNode* cur = root;
        while (cur!= NULL || !st.empty()) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur -> left; // 直接遍历到最底层的左节点 左
            } else { // 说明再向下的左节点没有了
                cur = st.top(); // 向上递归                
                res.push_back(cur -> val);  // 取值 这个值在左值右值中横跳 中
                st.pop();                   // 令上一层的节点成为头
                cur = cur -> right;         // 右
            }
        }
        return res;
    }
};
// 后序 左右中   前序 中左右    -> 中右左    最后翻转顺序
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        st.push(root);
        vector<int> res;
        if (root == NULL) return res;
        while (!st.empty()) {
            cur = st.top();
            res.push_back(cur ->val);
            st.pop();
            if (cur -> left) st.push(cur->left);  // 左
            if (cur -> right) st.push(cur -> right);//右
        }
        reverse(res.begin(),res.end());
        return res;
    }
};