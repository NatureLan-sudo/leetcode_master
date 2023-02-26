#include "common_include.h"
class Solution {
public:
    bool hassum(TreeNode* root, int count) {
        //终止条件
        if (!root ->left && !root->right && count == 0) return true;
        if (!root ->left && !root->right)  return false;
        //单层迭代
        if (root -> left) {
            if(hassum(root->left, count - root->left->val)) return true;
        }
        if (root -> right) {
            if(hassum(root -> right, count - root -> right -> val)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return hassum(root, targetSum - root->val);
    }
};