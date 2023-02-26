#include "common_include.h" 
//给你两棵二叉树 root 和 subRoot.检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
// 如果存在,返回 true ；否则，返回 false 。
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr && q != nullptr) return false;
        else if (p != nullptr && q == nullptr) return false;
        else if (p -> val !=  q->val) return false;
        bool left = isSame(p -> left, q->left);
        bool right = isSame(p->right, q->right);
        return left&&right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node -> val == subRoot ->val) {
                    bool same = isSame(node, subRoot);
                    if(same) return true;
                }
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
        }
        return false;
    }
};