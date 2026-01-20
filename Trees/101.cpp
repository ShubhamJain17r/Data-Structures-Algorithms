// Symmetric Tree

// https://leetcode.com/problems/symmetric-tree?envType=problem-list-v2&envId=v1lvhx8m

/*
Constraints:
    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isMirror(TreeNode* temp1, TreeNode* temp2) {
    if (!temp1 && !temp2) return true;
    if (!temp1 || !temp2) return false;

    if (temp1 -> val != temp2 -> val) return false;

    return isMirror(temp1 -> left, temp2 -> right) && isMirror(temp1 -> right, temp2 -> left); 
}
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root, root);
}