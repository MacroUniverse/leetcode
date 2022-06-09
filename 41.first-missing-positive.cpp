class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (nums[i] < 0)
                nums[i] = 0;
        }
        for (int i = 0; i < N; ++i) {
            int ind = abs(nums[i]) - 1;
            if (ind >= 0 && ind < nums.size())
                if (nums[ind] > 0)
                    nums[ind] *= -1;
                else if (nums[ind] == 0)
                    nums[ind] = -6e5;
        }
        for (int i = 0; i < N; ++i)
            if (nums[i] >= 0)
                return i + 1;
        return nums.size() + 1;
    }
};
