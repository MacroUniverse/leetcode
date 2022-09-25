/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *new_root = NULL;
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        helper(root);
        root->left = root->right = NULL;
        return new_root;
    }

    // relink 2 children
    void helper(TreeNode* node) {
        TreeNode *left = node->left;
        if (!left) {
            if (new_root == NULL)
                new_root = node;
            return;
        }
        helper(left);
        left->left = node->right;
        left->right = node;
    }
};
