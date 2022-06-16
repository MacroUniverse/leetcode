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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        try {helper(p, q);}
        catch (...) {return false;}
        return true;
    }
    
    void helper(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL || node2 == NULL) {
            if (node1 != NULL || node2 != NULL)
                throw false;
            return;
        }
        helper(node1->left, node2->left);
        if (node1->val != node2->val)
            throw false;
        helper(node1->right, node2->right);
    }
};
