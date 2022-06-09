class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ret1;
        vector<vector<int>> ret;
        helper(ret, ret1, candidates, 0, 0, 0, target);
        return ret;
    }
    
    void helper(vector<vector<int>> &ret, vector<int> &ret1, vector<int>& candidates, int ind, int start, int sum, int target) {
        if (ret1.capacity() < ind+1)
            ret1.emplace_back();
        int i, N = candidates.size();
        for (i = start; i < N; ++i) {
            int val_i = candidates[i];
            if (i > start && val_i == candidates[i-1])
                continue;                
            int tot = sum + val_i;
            if (tot > target)
                return;
            ret1.resize(ind+1);
            ret1[ind] = val_i;
            if (tot == target) {
                ret.push_back(ret1);
                return;
            }
            helper(ret, ret1, candidates, ind+1, i+1, tot, target);
        }
    }
};
