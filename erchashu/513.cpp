#include "common_include.h"
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
       int size = q.size();
       for (int i = 0; i< size;i++) {
        TreeNode* node = q.front();
        q.pop();
        if (i==0) res = node -> val; 
        if (node -> left) q.push(node ->left);
        if (node -> right) q.push(node ->right);
       }
    }
    return res;
    }
};
