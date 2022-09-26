class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> m; // last appearance index
        int i, N = s.size(), start = 0, max_len = 0;
        for (i = 0; i < N; ++i) {
            char c = s[i];
            m[c] = i;
            if (m.size() > k) {
                max_len = max(max_len, i - start);
                start = update(m) + 1;
            }
        }
        max_len = max(max_len, i - start);
        return max_len;
    }

    int update(unordered_map<char,int> &m) {
        int left_most = INT_MAX;
        unordered_map<char,int>::iterator it0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second < left_most)
                left_most = it->second, it0 = it;
        }
        m.erase(it0);
        return left_most;
    }
};
