class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if (N == 0)
            return "";
        else if (N == 1)
            return s;
        else if (N == 2) {
            if (s[0] == s[1])
                return s;
            else
                return s.substr(0, 1);
        }
        
        int len, odd_max_len = 0, odd_max_i, odd_max_j, even_max_len = 0, even_max_i, even_max_j;
        // odd substr
        for (int i = 1; i < N; ++i) {
            len = 1;
            for (int j = i + 1; j < N; ++j) {
                if (2*i - j < 0)
                    break;
                if (s[2*i - j] == s[j]) {
                    len += 2;
                    if (odd_max_len < len) {
                        odd_max_len = len;
                        odd_max_i = i; odd_max_j = j;
                    }
                }
                else
                    break;
            }            
        }
        // even substr
        for (int i = 0; i < N; ++i) {
            len = 0;
            for (int j = i + 1; j < N; ++j) {
                if (2*i - j + 1 < 0)
                    break;
                if (s[2*i - j + 1] == s[j]) {
                    len += 2;
                    if (even_max_len < len) {
                        even_max_len = len;
                        even_max_i = i; even_max_j = j;
                    }
                }
                else
                    break;
            }            
        }
        string sub;
        if (odd_max_len > even_max_len) {
            if (odd_max_len > 0)
                return s.substr(2*odd_max_i - odd_max_j, odd_max_len);
        }
        else {
            if (even_max_len > 0)
            return s.substr(2*even_max_i - even_max_j + 1, even_max_len);
        }
        return s.substr(0, 1);
    }
};
