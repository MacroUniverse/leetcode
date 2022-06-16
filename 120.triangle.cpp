class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        vector<int> row1(N+1,0), row2(N+1,0);
        for (int i = N-1; i >= 0; --i) {
            if (i % 2 == 0) {
                for (int j = 0; j <= i; ++j)
                    row1[j] = triangle[i][j] + min(row2[j], row2[j+1]);
            }
            else {
                for (int j = 0; j <= i; ++j)
                    row2[j] = triangle[i][j] + min(row1[j], row1[j+1]);
            }
        }
        return row1[0];
    }
};
