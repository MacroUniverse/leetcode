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
