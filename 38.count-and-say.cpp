class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string in = "1", out;
        for (int i = 1; i < n; ++i) {
            helper(out, in);
            in = out;
        }
        return out;
    }
    
    void helper(string &out, string& in) {
        int i, N = in.size(), count = 1;
        char d = in[0];
        out.clear();
        for (i = 1; i < N; ++i) {
            if (in[i] == d) {
                ++count;
            }
            else {
                out += to_string(count); out += d;
                count = 1; d = in[i];
            }
        }
        out += to_string(count); out += d;
    }
};
