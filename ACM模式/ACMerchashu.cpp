/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2023-03-14 21:46:59
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2023-03-15 11:50:39
 * @FilePath: /test/ACMerchashu.cpp
 * @brief: 在ACM模式下构造二叉树
 * 
 * Copyright (c) 2023 by Nature, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;
// 输入的是一个数组，数组是层序遍历的顺序。因此我们是根据数组构造二叉树。
// https://www.nowcoder.com/discuss/460145181203931136?sourceSSR=post
struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};
TreeNode* buildTree(vector<int> &input) {
    vector<TreeNode*> vecTree(input.size(), nullptr); // 初始化vec存储树节点
    TreeNode* root = nullptr; // 初始化根结点
    // 构造节点并存入到vec
    for (int i = 0; i < input.size(); i++) {
        TreeNode* node = nullptr;
        if (input[i] != -1) {
            node = new TreeNode(input[i]);
            vecTree[i] = node;
        } else {
            vecTree[i] = node;
        }
        if ( i == 0) root = node;
    }
    // 构造节点之间的链接关系
    for (int i = 0; 2 * i +1 < vecTree.size(); i++) {
        vecTree[i] -> left = vecTree[2 * i + 1];
        if (2*i + 2 < vecTree.size()) {
            vecTree[i] -> right = vecTree[2 * i + 2];
        }
    }
    return root;
}
int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    TreeNode* root = buildTree(input);
    // 获得根节点，已经是构造好的二叉树了，后面进行题目就可以了
    
}

// 二叉树染色类的题目，二叉树怎么构造
// 第一行输入一个正整数n 。 接下来 n−1行，每行两个正整数 u,v ,表示u号节点和v号节点之间有一条边。
// 保证输入是一棵树。