#include "common_include.h"

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归遍历，前序
class Solution {
public:
    void qianxu(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;
        res.push_back(root -> val);
        if (root -> left) qianxu(root->left,res);
        if (root -> right) qianxu(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {// 中左右边
        vector<int> res;
        qianxu(root,res);
        return res;
    }
};
// 层次遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i< size; i++) {
                TreeNode*  node = q.front();
                q.pop();
                vec.push_back(node -> val);
                if (node -> left) q.push(node ->left);
                if (node ->right) q.push(node ->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// 深度遍历，统一迭代方法，前序
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {// 中左右边
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node -> right) st.push(node -> right);
                if (node -> left) st.push(node ->left);
                st.push(node);
                st.push(nullptr);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node -> val);
            }
        }
        return res;
    }
};
// 二叉树翻转
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { // 相当于前序，中左右
        if(root == nullptr) return root;
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};
// 对称二叉树
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && left == nullptr) return true;
        else if (left ->val != right -> val)  return false;
        return compare(left->left,right -> right)&&compare(left -> right, right ->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return compare(root->left, root -> right);
    }
};
// 最大深度，实际上是求最大高度，求根节点到叶子节点的最远路径
class Solution {
public:
    int getdepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0;
        int right = 0;
        if (root -> left) left = getdepth(root -> left);
        if (root -> right) right = getdepth(root -> right);
        int depth;
        depth = 1 + max(left,right);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return getdepth(root);
    }
};
// 最小深度, 从根节点到叶子节点的最近距离;
// 迭代的方法
class Solution {
public:
    int getdepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getdepth(root-> left);
        int right = getdepth(root -> right);
        if (root -> left != nullptr && root -> right == nullptr) {
            return 1 + left;
        }
        if (root ->right != nullptr && root -> left == nullptr) {
            return 1 + right;
        }
        return 1 + min(left, right);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return getdepth(root);
    }
};
// 层次遍历的方法也可以，在加入一个节点的时候，判断他的左右节点是否存在，如果不存在，说明到了