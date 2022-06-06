class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vstr;
        string str; str.resize(2*n);
        fun1(vstr, str, n, n, n);
        return vstr;
    }
    
    void fun1(vector<string> &vstr, string &str, int left, int right, int n) {
        if (left > right)
            return;
        int ind = 2*n - left - right;
        if (left > 0) {
            str[ind] = '(';
            fun1(vstr, str, left-1, right, n);
        }
        if (right > 0) {
            str[ind] = ')';
            fun1(vstr, str, left, right-1, n);
        }
        else if (left == 0) {
            vstr.push_back(str);
        }
    }
};
