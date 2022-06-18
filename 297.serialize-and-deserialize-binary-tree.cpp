/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        helper(str, root);
        return str;
    }
    
    void helper(string &str, TreeNode *node) {
        if (node == NULL) {
            num2bin(str, INT_MAX); return;
        }
        num2bin(str, node->val);
        helper(str, node->left);
        helper(str, node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* node;
        int ind = 0;
        helper2(data, ind, node, NULL);
        return node;
    }
    
    void helper2(const string &data, int &ind, TreeNode* &node, TreeNode* root) {
        int val = bin2int(&data[ind]); ind+=4;
        if (val == INT_MAX) {
            node = NULL; return;
        }
        node = new TreeNode(val);
        if (root == NULL) root = node;
        helper2(data, ind, node->left, root);
        helper2(data, ind, node->right, root);
    }
    
    void num2bin(string &s, int n) {
        char *p = (char *)&n;
        s.push_back(p[0]);
		s.push_back(p[1]);
		s.push_back(p[2]);
		s.push_back(p[3]);
    }
    
    int bin2int(const char *c) {
        return *((int *)c);
    }
};
