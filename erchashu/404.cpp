#include "common_include.h"
class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root) {
            if (root == nullptr) return 0;
            int left = sumOfLeftLeaves(root -> left);
            int right = sumOfLeftLeaves(root -> right);
            int mid = 0;
            if (root -> left !=nullptr && root -> left -> left==nullptr && root -> left -> right == nullptr)
            {
                mid = root -> left -> val;
            }
            int sum = left + right + mid;
            return sum;
        }
    
};