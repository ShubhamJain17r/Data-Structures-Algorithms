// Binary Tree Preorder Traversal

// https://leetcode.com/problems/binary-tree-preorder-traversal?envType=problem-list-v2&envId=v1lvhx8m

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

void preorderTraversal(TreeNode* root, vector<int> &preOrder) {
    if (!root) return;
    preOrder.push_back(root->val);
    preorderTraversal(root -> left, preOrder);
    preorderTraversal(root -> right, preOrder);
}
vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> preOrder;
    // preorderTraversal(root, preOrder);       // recursive code

    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        preOrder.push_back(node -> val);
        if (node -> right)
            st.push(node->right);
        if (node -> left)
            st.push(node->left);
    }
    return preOrder;
}