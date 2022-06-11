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
    void recoverTree(TreeNode* root) {        
        vector<TreeNode*> pair;
        traverse(root, NULL, pair);
        if (pair.size() == 2)
            swap(pair[0]->val, pair[1]->val);
        else
            swap(pair[0]->val, pair[2]->val);
    }
    
    TreeNode* traverse(TreeNode* node, TreeNode* last, vector<TreeNode*> &pair) {
        if (node->left != NULL) {
            last = traverse(node->left, last, pair);
            if (last == NULL)
                return NULL;
        }
        if (last != NULL && last->val > node->val) {
            if (pair.size() == 0) {
                pair.push_back(last);
                pair.push_back(node);
            }
            else {
                pair.push_back(node);
                return NULL;
            }
        }
        if (node->right != NULL)
            return traverse(node->right, node, pair);
        return node;
    }
};
