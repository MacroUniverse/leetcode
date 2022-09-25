class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if (nums.empty()) {
            helper(ret, lower-1, upper+1); return ret;
        }
        helper(ret, lower-1, nums[0]);
        int n1 = nums.size()-1;
        for (int i = 0; i < n1; ++i)
            helper(ret, nums[i], nums[i+1]);
        helper(ret, nums.back(), upper+1);
        return ret;
    }

    // open interval
    void helper(vector<string> &ret, int i, int j) {
        int n = j - i;
        if (n <= 1) return;
        if (n == 2)
            ret.push_back(to_string(i+1));
        else
            ret.push_back(to_string(i+1) + "->" + to_string(j-1));
    }
};
