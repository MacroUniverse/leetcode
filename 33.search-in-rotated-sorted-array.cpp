class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size(), iL = 0, iR = N-1, k;
        if (N <= 4) {
            for (int i = 0; i < N; ++i)
                if (target == nums[i])
                    return i;
            return -1;
        }
        if (nums[iR] > nums[iL]) {
            k = 0;
            if (target < nums[0] || target > nums[N-1])
                return -1;
            if (target == nums[0])
                return 0;
            if (target == nums[N-1])
                return N-1;
            iL = 0; iR = N-1;
        }
        else {
            while (iL < iR - 1) {
                int i = (iL+iR)/2;
                if (nums[i] < nums[iL])
                    iR = i;
                else
                    iL = i;
            }
            k = iR;
            if (target < nums[k] || target > nums[k-1])
                return -1;
            if (target == nums[k])
                return k;
            if (target == nums[k-1])
                return k-1;
            if (target >= nums[0]) {
                if (target == nums[0])
                    return 0;
                iL = 0; iR = k-1;
            }
            else {
                if (target == nums[N-1])
                    return N-1;
                iL = k; iR = N-1;
            }
        }
        while (iL < iR - 1) {
            int i = (iL+iR)/2;
            if (target < nums[i])
                iR = i;
            else if (target > nums[i])
                iL = i;
            else
                return i;
        }
        return -1;
    }
};
