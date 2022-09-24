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


// 第二次做
class Solution {
public:
    int numDecodings(string s) {
        // -1: unvisited, 0: dead end
        vector<int> ways(s.size(), -1); ways.push_back(1);
        helper(s, 0, ways);
        return ways[0];
    }

    // update ways[ind]
    void helper(string &s, int ind, vector<int> &ways) {
        if (ways[ind] >= 0)
            return;
        char c1 = s[ind];
        if (c1 == '0') {
            ways[ind] = 0; return;
        }
        else if (ind == s.size()-1) {
            ways[ind] = 1; return;
        }
        else if (c1 == '1') {
            helper(s, ind+1, ways);
            ways[ind] = ways[ind+1];
            helper(s, ind+2, ways);
            ways[ind] += ways[ind+2];
            return;
        }
        else if (c1 == '2') {
            helper(s, ind+1, ways);
            ways[ind] = ways[ind+1];
            char c2 = s[ind+1];
            if (c2 > '6')
                return;
            helper(s, ind+2, ways);
            ways[ind] += ways[ind+2];
            return;
        }
        else { // c1 >= '3'
            helper(s, ind+1, ways);
            ways[ind] = ways[ind+1];
        }
    }
};
