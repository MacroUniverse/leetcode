class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty())
            return word2.size();
        if (word2.empty())
            return word1.size();
        int N1 = word1.size(), N2 = word2.size();
        vector<vector<int>> mat(N1+1);
        for (int i = 0; i <= N1; ++i)
            mat[i].resize(N2+1);
        mat[0][0] = 0;
        for (int i = 1; i <= N1; ++i)
            mat[i][0] = i;
        for (int j = 1; j <= N2; ++j)
            mat[0][j] = j;
        for (int i = 1; i <= N1; ++i) {
            for (int j = 1; j <= N2; ++j) {
                if (word1[i-1] == word2[j-1])
                    mat[i][j] = mat[i-1][j-1];
                else
                    mat[i][j] = 1 + min(mat[i-1][j], min(mat[i][j-1], mat[i-1][j-1]));
            }
        }
        return mat[N1][N2];
    }
};
