// Invert Binary Tree

// https://leetcode.com/problems/invert-binary-tree?envType=problem-list-v2&envId=v1lvhx8m

/*
Constraints:
    The number of nodes in the tree is in the range [0, 100].
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

void invert(TreeNode* node, TreeNode* ans) {        
    if (node -> left) {
        ans -> right = new TreeNode(node -> left -> val);

        invert(node -> left, ans -> right);
    }
    if (node -> right) {
        ans -> left = new TreeNode(node -> right -> val);
        
        invert(node -> right, ans -> left);
    }

}
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* ans = new TreeNode(root -> val);
    invert(root, ans);
    return ans;
}