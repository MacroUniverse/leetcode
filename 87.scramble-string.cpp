class Solution {
public:
    bool isScramble(string s1, string s2) {
		unordered_map<string, bool> mp;
        return helper(s1, 0, s2, 0, s1.size(), mp);
    }
    
    bool helper(string &s1, int b1, string &s2, int b2, int N, unordered_map<string, bool> &mp)
    {
		string s1s2 = s1.substr(b1, N) + s2.substr(b2, N);
		if (mp.count(s1s2))
            return mp[s1s2];
        if (N == 1) return mp[s1s2] = (s1[b1] == s2[b2]);
        int e1 = b1 + N, e2 = b2 + N, max_ind = b2-1, min_ind = e2;
        vector<bool> checkL(N, true), checkR(N, true);
        for (int i = b1; i < e1-1; ++i) {
            char c = s1[i];
            int j;
			// no swap
            for (j = b2; j < e2; ++j) {
                if (checkL[j] && s2[j] == c) {
                    max_ind = max(max_ind, j); checkL[j] = false;
                    if (i-b1 == max_ind-b2 && helper(s1, b1, s2, b2, i+1-b1, mp) &&
                                helper(s1, i+1, s2, max_ind+1, e1-i-1, mp))
                        return mp[s1s2] = true;
                    break;
                }
            }
            if (j == e2) return mp[s1s2] = false;
			// swap
            for (j = e2-1; j >= b2; --j) {
                if (checkR[j] && s2[j] == c) {
                    min_ind = min(min_ind, j); checkR[j] = false;
                    if (i-b1 == e2-1 - min_ind && helper(s1, b1, s2, min_ind, i+1-b1, mp) &&
                                helper(s1, i+1, s2, b2, e1-i-1, mp))
                        return mp[s1s2] = true;
                    break;
                }
            }
        }
        return mp[s1s2] = false;
    }
};
