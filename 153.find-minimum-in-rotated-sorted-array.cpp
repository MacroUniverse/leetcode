class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int L = nums[l], R = nums[r];
        if (L < R)
            return L;
        while (r - l > 1) {
            int m = (l + r)/2, M = nums[m];
            if (L < M)
                l = m, L = M;
            else
                r = m, R = M;
        }
        return R;
    }
};
