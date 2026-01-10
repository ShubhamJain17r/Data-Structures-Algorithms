// Binary Tree Postorder Traversal

// 

/*

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

void postorderTraversal(TreeNode* node, vector<int> &postOrder) {
    if (!node) return;
    postorderTraversal(node -> left, postOrder);
    postorderTraversal(node -> right, postOrder);
    postOrder.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {        // using recursion
    if (!root) return {};
    vector<int> postOrder;
    postorderTraversal(root, postOrder);
    return postOrder;
}

// Iterative method - 2 stacks
vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> postOrder;
    // postorderTraversal(root, postOrder);

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    s1.push(root);

    while (!s1.empty()) {           // modified preorder traversal : root -> right -> left
        TreeNode* node = s1.top(); s1.pop();
        s2.push(node);              // store in another stack to reverse (left -> right -> root), can also store in postOrder directly just reverse it at last

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty()) {
        TreeNode* node = s2.top(); s2.pop();
        postOrder.push_back(node->val);
    }
    return postOrder;
}