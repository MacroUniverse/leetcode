class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int N = nums.size();
        int val;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            val = nums[i] + nums[i+1] + nums[i+2];
            if (val > 0)
                goto label;
            else if (val == 0) {
                ret.push_back({nums[i],nums[i+1],nums[i+2]});
                break;
            }
            val = nums[i] + nums[N-2] + nums[N-1];
            if (val < 0)
                continue;
            else if (val == 0) {
                ret.push_back({nums[i],nums[N-2],nums[N-1]});
                continue;
            }
            int j = i+1, k = N-1, sum2 = -nums[i];
            while (j < k) {
                val = nums[j] + nums[k];
                if (val > sum2)
                    while (j < --k && nums[k] == nums[k+1]);
                else if (val < sum2)
                    while (++j < k && nums[j] == nums[j-1]);
                else {
                    ret.push_back({nums[i],nums[j],nums[k]});
                    while (j < --k && nums[k] == nums[k+1]);
                    while (++j < k && nums[j] == nums[j-1]);
                }
            }
        }
        label:
        if (ret.size() == 1 && ret[0].empty())
            ret.clear();
        return ret;
    }
};
