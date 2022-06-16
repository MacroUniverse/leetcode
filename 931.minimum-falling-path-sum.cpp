class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if (N == 1)
            return matrix[0][0];
        vector<int> row11(N, 0), row22(N, 0);
        for (int row = N - 1; row >= 0; row--) {
            if (row % 2 == 0)
                helper(matrix, row, row11, row22);
            else
                helper(matrix, row, row22, row11);
        }
        return *min_element(row11.begin(), row11.end());
    }
    
    void helper(vector<vector<int>>& matrix, int row, vector<int> &row1, vector<int> &row2) {
        int N = matrix.size();
        for (int col = 0; col < N; col++) {
            if (col == 0) {
                row1[col] =
                    min(row2[col], row2[col + 1]) + matrix[row][col];
            } else if (col == N - 1) {
                row1[col] =
                    min(row2[col], row2[col - 1]) + matrix[row][col];
            } else {
                row1[col] =
                    min(row2[col], min(row2[col + 1], row2[col - 1])) +
                    matrix[row][col];
            }
        }
    }
};
