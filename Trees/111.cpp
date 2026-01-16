// Minimum Depth of Binary Tree

// https://leetcode.com/problems/minimum-depth-of-binary-tree?envType=problem-list-v2&envId=v1lvhx8m

/*
Constraints:
    The number of nodes in the tree is in the range [0, 10^5].
    -1000 <= Node.val <= 1000
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

int minDepth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 0;
    bool found = false;

    while (!found && !q.empty()) {
        int sz = q.size();
        while (sz--) {                              // level order traversal
            TreeNode* node = q.front(); q.pop();

            if (!node->left && !node->right) {      // first encountered leaf node
                found = true;
                break;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        depth++;
    }
    return depth;
}