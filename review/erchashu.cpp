#include "common_include.h"
// 二叉树递归遍历
// 前序
class Solution {
public:
    vector<int> qianxu(TreeNode* root, vector<int> &res) {
        if (root == nullptr)  return res;
        // 其他遍历方式只需要调整这几个的顺序即可
        res.push_back(root -> val); //中
        qianxu(root -> left, res);  //左
        qianxu(root -> right, res); //右
        return res;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(10);
        qianxu(root,res);
        return res;
    }
};
// 二叉树统一迭代遍历
// 前序
// 这种遍历是需要用栈的，层序遍历是用队列的
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(10);
        if(root == nullptr)  return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) { // 没有标志
                st.pop();
                // 由于我们希望只在中间节点后面加上标志物，所以我们需要保证其他在st中的节点不为空
                if(node -> right) st.push(node -> right); // 右
                if(node -> left) st.push(node -> left);  // 左
                st.push(node);          // 中
                st.push(nullptr);       // 在中后面加标志
            } else {
                st.pop();
                TreeNode* node = st.top();
                st.pop();
                res.push_back(node -> val);
            }
        }
        return res;
    }
};
// 二叉树层序遍历
// 层序遍历是使用队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        res.reserve(10);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            vec.reserve(5);
            for (int i = 0; i < size; i++) {
                TreeNode* node =  q.front();
                q.pop();
                vec.push_back(node -> val);
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// 翻转二叉树
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        swap(root -> left, root -> right);
        // 由于第一句就是判断root是不是为空，所以这里直接调用不用判断
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};
// 判断是否为对称二叉树
class Solution {
public:
    bool duichen(TreeNode* left, TreeNode*right) {
        if (left == nullptr && right!=nullptr || left!= nullptr && right ==nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left -> val!= right -> val) return false;
        bool outside = duichen(left -> left, right -> right);
        bool inside = duichen(left -> right, right -> left);
        return outside&&inside;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return duichen(root -> left, root -> right);
    }
};
// 二叉树的最大深度
// 根节点到最远叶子节点的个数
class Solution {
public:
    int getdepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getdepth(root -> left);
        int right = getdepth(root -> right);
        int depth = 1 + max(left, right);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};
// 最小深度
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
class Solution {
public:
    int getdepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getdepth(root -> left);
        int right = getdepth(root -> right);
        if (root -> left == nullptr && root -> right != nullptr) return 1 + right;
        else if (root -> left != nullptr && root -> right ==nullptr) return 1 + left;
        return 1 + min(left, right);
    }
    int minDepth(TreeNode* root) {
        return getdepth(root);
    }
};
// 完全二叉树的节点个数
// 什么是完全二叉树
// 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^(h-1)  个节点。
// 判断是不是满二叉树，如果不是满二叉树就向左右孩子递归，然后找到满二叉树。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        // 存在顶点
        int leftdepth = 1;
        int rightdepth = 1;
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        while (left) {
            leftdepth++;
            left = left -> left;
        }
        while(right) {
            rightdepth++;
            right = right -> right;
        }
        if (leftdepth == rightdepth) {
            // 说明是满二叉树，那么可以直接计算
            return (2 << (leftdepth - 1)) -1;
        }
        return countNodes(root -> left)+countNodes(root -> right)+1;
    }
};
// 平衡二叉树
class Solution {
public:
    int getdepth (TreeNode* node) {
        if (node == nullptr) return 0;
        int left =0 ,right = 0;
        if (node -> left) left = getdepth(node -> left);
        if (node -> right) right = getdepth(node ->right);
        if (left == -1 || right ==-1) return -1;
        if (abs(left- right) <=1) return 1 + max(left, right); // 在循环里 因此可以判断每一个节点
        return -1;
    }
    bool isBalanced(TreeNode* root) {
       return getdepth(root)!= -1;
    }
};
// 二叉树的所有路径
class Solution {
public:
    void lujing(TreeNode* node, vector<string> &res, string path) {
        path += to_string(node -> val);
        if (node -> right == nullptr && node -> left == nullptr)  {
            // 说明到达叶子节点了，加入到结果中
            res.push_back(path);
            return;
        }
        // 如果还没到叶子节点
        if(node -> left) lujing(node -> left, res, path + "->");
        if(node -> right) lujing(node -> right, res, path + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        res.reserve(10);
        if (root == nullptr) return res;
        lujing(root, res, path);
        return res;
    }
};