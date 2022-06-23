class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
    
    bool helper(vector<vector<char>> & board, int i, int j) {
        if (i == board.size()) return true;
        if (j == board.size()) return helper (board, i+1, 0);
        if (board[i][j] != '.') return helper(board, i, j+1);
        for (char c = '1'; c <= '9'; ++c) {
            if (!is_valid(board, i, j, c)) continue;
            board[i][j] = c;
            if (helper (board, i, j+1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    
    bool is_valid (vector<vector<char>>& board, int i, int j, char c) {
        for (int i = 0; i < board.size(); ++i)
            if (board[i][j] == c) return false;
        for (int j = 0; j < board.size(); ++j)
            if (board[i][j] == c) return false;
        int row = i - i%3, col = j - j%3;
        for (i = row; i < row + 3; ++i)
            for (j = col; j < col + 3; ++j)
                if (board[i][j] == c) return false;
        return true;
    }
};
