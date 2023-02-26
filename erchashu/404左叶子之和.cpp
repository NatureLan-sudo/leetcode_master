#include "common_include.h"
// 返回所有左叶子之和
class Solution {
public:
    int getsum(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftsum = getsum(root -> left);
        int rightsum = getsum(root -> right);
        int mid = 0;
        if (root -> left!= nullptr && root -> left -> left == nullptr && root -> left -> right ==nullptr) {
            mid = root -> left ->val;
        }
        return leftsum + rightsum + mid;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return getsum(root);
    }
};
class test {
    public:
        int ma;
        int mb;
        void make(int a, int b);
    private:
        int mk;
        int md;

};
void test::make(int a, int b) {
    mk = a;
    md = b;
}
int main() {
    test A;
    A.make(1,3);
    
}