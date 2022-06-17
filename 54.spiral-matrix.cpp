class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n-1, up = 0, low = m-1;
        vector<int> ret; ret.reserve(m*n);
        while (1) {
            for (int j = left; j < right; ++j)
                ret.push_back(matrix[up][j]);
            if (up == low) {
                ret.push_back(matrix[up][right]); return ret;
            }
            for (int i = up; i < low; ++i)
                ret.push_back(matrix[i][right]);
            if (left == right) {
                ret.push_back(matrix[low][left]); return ret;
            }
            for (int j = right; j > left; --j)
                ret.push_back(matrix[low][j]);
            for (int i = low; i > up; --i)
                ret.push_back(matrix[i][left]);
            ++up; --low; ++left; --right;
            if (up > low || left > right)
                return ret;
        }
    }
};
