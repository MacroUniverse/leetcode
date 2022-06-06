class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, N = nums.size();
        for (i = N-2; i >= 0; --i) {
            if (nums[i] < nums[i+1])
                break;
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        for (j = i+1; j < N; ++j) {
            if (nums[j] <= nums[i])
                break;
        }
        swap(nums[i], nums[j-1]);
        sort(&nums[i+1], &nums[N]);
    }
};
