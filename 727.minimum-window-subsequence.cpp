class Solution {
public:
    string minWindow(string s1, string s2) {
        int i = 0, j = 0, i0, i0_min = -1, len_min = 2e4+1, N1 = s1.size(), N2 = s2.size();
        char c = s2[0];
        while (i < N1) {
            if (s1[i] == c) {
                if (j == 0) i0 = i;
                if (++j == N2) {
                    int len = i+1-i0;
                    if (len < len_min)
                        len_min = len, i0_min = i0;
                    j = 0; c = s2[0]; i = i0 + 1; continue;
                }
                else
                    c = s2[j];
            }
            ++i;
        }
        return i0_min < 0 ? "" : s1.substr(i0_min, len_min);
    }
};

// high performance

class Solution {
public:
    string minWindow(string s1, string s2) {
        int i = 0, j = 0, i0, i0_min = -1, len_min = 2e4+1, N1 = s1.size(), N2 = s2.size();
        char c = s2[0];
        while (1) {
            while (i < N1) {
                if (s1[i] == c) {
                    if (++j == N2) {
                        if (N2 == 1) return s1.substr(i, 1);
                        j = N2-2; i0 = i-1; c = s2[N2-2]; break;
                    }
                    else
                        c = s2[j];
                }
                ++i;
            }
            if (i == N1) break;
            while (1) {
                if (s1[i0] == c) {
                    if (--j < 0) {
                        int len = i+1-i0;
                        if (len < len_min) len_min = len, i0_min = i0;
                        j = 0; c = s2[0]; i = i0 + 1; break;
                    }
                    c = s2[j];
                }
                --i0;
            }
        }
        return i0_min < 0 ? "" : s1.substr(i0_min, len_min);
    }
};
