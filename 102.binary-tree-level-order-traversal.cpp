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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        vector<TreeNode*> nodes, next_nodes;
        nodes.push_back(root);
        ret.emplace_back();
        helper(ret, nodes, next_nodes);
        return ret;
    }
    
    void helper(vector<vector<int>> &ret, vector<TreeNode*> &nodes, vector<TreeNode*> &next_nodes) {
        for (auto &node: nodes) {
            ret.back().push_back(node->val);
            if (node->left != NULL)
                next_nodes.push_back(node->left);
            if (node->right != NULL)
                next_nodes.push_back(node->right);
        }
        if (next_nodes.size() > 0) {
            ret.emplace_back();
            nodes.clear();
            helper(ret, next_nodes, nodes);
        }
    }
};
