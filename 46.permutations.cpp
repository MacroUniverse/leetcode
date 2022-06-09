class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v(nums.size());
        vector<vector<int>> ret;
        int N = nums.size();
        helper(ret, nums, 0, N);
        return ret;
    }
    
    void helper(vector<vector<int>> &ret, vector<int> &nums, int ind, int N) {
        if (ind == N-1) {
            ret.push_back(nums); return;
        }
        for (int i = ind; i < N; ++i) {
            if (i != ind) {
                swap(nums[i], nums[ind]);
                helper(ret, nums, ind+1, N);
                swap(nums[i], nums[ind]);
            }
            else {
                helper(ret, nums, ind+1, N);
            }
        }
    }
};
