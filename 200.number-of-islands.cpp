class Solution {
public:
    int N0, N1;
    int numIslands(vector<vector<char>>& grid) {
        N0 = grid.size(), N1 = grid[0].size();
        int count = 0;
        for (int i = 0; i < N0; ++i) {
            for (int j = 0; j < N1; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    erase(grid, i, j);
                }
            }
        }
        return count;
    }

    void erase(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        if (i > 0)
            erase(grid, i-1, j);
        if (i < N0-1)
            erase(grid, i+1, j);
        if (j > 0)
            erase(grid, i, j-1);
        if (j < N1-1)
            erase(grid, i, j+1);
    }
};
