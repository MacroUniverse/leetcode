class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        return v;
    }
    
    void traverse(TreeNode* node, vector<int> &v) {
        if (node == NULL)
            return;
        traverse(node->left, v);
        v.push_back(node->val);
        traverse(node->right, v);
    }
};
