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
    bool isValidBST(TreeNode* root) {
        if (helper(root, NULL) == NULL)
            return false;
        return true;
    }
    
    TreeNode * helper(TreeNode* node, TreeNode* last) {
        if (node->left != NULL) {
            last = helper(node->left, last);
            if (last == NULL)
                return NULL;
        }
        if (last != NULL && last->val >= node->val)
            return NULL;
        if (node->right != NULL) {
            return helper(node->right, node);
        }
        return node;
    }
};

class Solution {
public:
    TreeNode* last = NULL;
    
    bool isValidBST(TreeNode* root) {
        try{helper(root);}
		catch (...) { return false; }
		return true;
    }
    
    void helper(TreeNode* node) {
        if (node == NULL) return;
        helper(node->left);
        if (last != NULL && last->val >= node->val)
            throw false;
        last = node;
        helper(node->right);
    }
};
