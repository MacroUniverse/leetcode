class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1)
            return 1;
        int max = 0;
        for (int i = 0; i < s.size() - max; ++i) {
            for (int j = i+1; j < s.size(); ++j) {
                cout << "i = " << i << " j = " << j << endl;
                int k = check(s, i, j);
                cout << "k = " << k << endl;
                if (k >= 0) {
                    i = k + 1;
                }
                int len = j - i + 1;
                if (len > max)
                    max = len;
            }
        }
        return max;
    }
    
    int check(const string &s, int start, int ind) {
        char c = s[ind];
        for (int i = start; i < ind; ++i) {
            if (s[i] == c)
                return i;
        }
        return -1;
    }
};
