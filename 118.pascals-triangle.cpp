class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        ret[0].push_back(1);
        for (int i = 1; i < numRows; ++i) {
            vector<int> &row = ret[i], &last_row = ret[i-1];
            row.resize(i+1);
            row[0] = row[i] = 1;
            for (int j = 1; j < i; ++j) {
                row[j] = last_row[j-1] + last_row[j];
            }
        }
        return ret;
    }
};
