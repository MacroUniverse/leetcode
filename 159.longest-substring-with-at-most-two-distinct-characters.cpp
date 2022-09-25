class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i, nmax = 1, i_last = 0, ind0 = 0;
        char c_last, c1 = s[0], c2;
        for (i = 1; i < s.size(); ++i) {
            char c = s[i];
            if (c != c1) {
                c2 = c; break;
            }
        }
        if (i == s.size()) return s.size();
        c_last = c2; i_last = i;
        for (++i; i < s.size(); ++i) {
            char c = s[i];
            if (c != c_last) {
                if (c != c1 && c != c2) {
                    nmax = max(nmax, i - ind0);
                    ind0 = i_last;
                    c1 = s[ind0]; c2 = s[i];
                }
                i_last = i; c_last = c;
            }
        }
        nmax = max(nmax, i - ind0);
        return nmax;
    }
};
