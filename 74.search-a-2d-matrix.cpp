class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        if (target == matrix[0][0] || target == matrix.back().back())
            return true;
        int N1 = matrix[0].size();
        int iL = 0, iR = matrix.size()*N1 - 1;
        while (iL < iR - 1) {
            int i = (iL + iR)/2, a = matrix[i / N1][i % N1];
            if (target < a)
                iR = i;
            else if (target > a)
                iL = i;
            else
                return true;
        }
        return false;
    }
};
