// Binary Tree Inorder Traversal

//https://leetcode.com/problems/binary-tree-inorder-traversal?envType=problem-list-v2&envId=v1lvhx8m

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

void inorderTraversal(TreeNode* root, vector<int> &inOrder) {
    if (!root) return;

    inorderTraversal(root->left, inOrder);
    inOrder.push_back(root->val);
    inorderTraversal(root->right, inOrder);
}
vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> inOrder;
    // inorderTraversal(root, inOrder);

    stack<TreeNode*> st;
    TreeNode* node = root;
    while (node || !st.empty()) {
        while (node) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();

        inOrder.push_back(node->val);
        node = node->right;
    }
    return inOrder;
}