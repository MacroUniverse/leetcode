// 93%, 90%
class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        if (numRows == 1 || s.size() <= numRows) return s;
        int N1 = 2*(numRows-1), n = s.size() / N1, rem = s.size() % N1;
        for (int i = 0; i < s.size(); i += N1)
            ret.push_back(s[i]);
        for (int row = 1; row < numRows-1; ++row) {
            ret.push_back(s[row]);
            for (int i = N1; ; i += N1) {
                if (i - row < s.size()) ret.push_back(s[i-row]);
                else break;
                if (i + row < s.size()) ret.push_back(s[i+row]);
                else break;
            }
        }
        for (int i = numRows-1; i < s.size(); i += N1)
            ret.push_back(s[i]);
        return ret;
    }
};

// 40%
class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.size(), k = 0;
        if (N == 0)
            return "";
        vector<string> strs(numRows);
        
        try {
            while (true) {
                for (int i = 0; i < numRows; ++i) {
                    strs[i] += s[k];
                    if (++k == N)
                        throw 0;
                }
                for (int i = numRows-2; i > 0; --i) {
                    strs[i] += s[k];
                    if (++k == N)
                        throw 0;
                }
            }
        }
        catch(int) {}
        string str;
        for (int i = 0; i < numRows; ++i)
            str += strs[i];
        return str;
    }
};
