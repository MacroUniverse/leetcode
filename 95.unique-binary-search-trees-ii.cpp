class Solution {
public:
    vector<TreeNode*> create(int start, int end) {
        if(start > end) return {NULL};
        vector<TreeNode*> ans;
        for(int i = start; i <= end; i++) {
            vector<TreeNode* >left = create(start, i - 1);
            vector<TreeNode* >right = create(i + 1, end);
            for(auto _left: left) {
                for(auto _right: right) {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = _left;
                    temp->right = _right;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return create(1, n);
    }
};
