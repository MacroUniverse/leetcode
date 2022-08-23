class Solution {
public:
    int numDecodings(string s) {
        vector<int> count(s.size(), -1);
        count.push_back(1);
        helper(s, count, 0);
        return count[0];
    }

    void helper(const string &s, vector<int> &count, int ind) {
        int N = 0;
        // dead end
        if (s[ind] == '0') { count[ind] = 0; return; }
        // try 1 digit
        if (count[ind+1] < 0)
            helper(s, count, ind+1);
        N += count[ind+1];
        // 2 digits impossible
        if (ind >= s.size()-1 || s[ind] > '2' || (s[ind] == '2' && s[ind+1] > '6')) {
            count[ind] = N; return;
        }
        // try 2 digits
        if (count[ind+2] < 0)
            helper(s, count, ind+2);
        N += count[ind+2];
        count[ind] = N;
    }
};
