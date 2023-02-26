#include "common_include.h"
//一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。注意 是每个节点！
// 比较高度，使用的是后序遍历。比较深度，使用的是前序遍历
 struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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