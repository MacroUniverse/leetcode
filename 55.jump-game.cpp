class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> mask(nums.size(), false);
        return helper(nums, 0, mask);
    }
    
    bool helper(vector<int>& nums, int ind, vector<bool>& mask) {
        int max = nums[ind];
        if (ind + max >= nums.size() - 1)
            return true;
        if (max == 0)
            return false;
        for (int i = ind+max; i >= ind+1; --i) {
            if (mask[i])
                continue;
            mask[i] = true;
            if (helper(nums, i, mask))
                return true;
        }
        return false;
    }
};

// best solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        for (int i = last-1; i >= 0; --i) {
            if (i + nums[i] >= last)
                last = i;
        }
        if (last == 0)
            return true;
        return false;
    }
};
