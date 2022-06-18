class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int Nk = key.size(), Nr = ring.size();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < Nr; ++i)
            mp[ring[i]].push_back(i);
        // dp[k][j] is the min rotation steps to reach key[k] at mp[key[k]][j]
        vector<vector<int>> dp; dp.resize(Nk);
        for (int i : mp[key[0]])
            dp[0].push_back(min(i, Nr - i));
        for (int k = 1; k < Nk; ++k) {
            char c = key[k], c0 = key[k-1];
            dp[k].resize(mp[c].size());
            for (int i = 0; i < mp[c].size(); ++i) {
                int ind = mp[c][i];
                int min_dist = INT_MAX;
                for (int i0 = 0; i0 < mp[c0].size(); ++i0) {
                    int ind0 = mp[c0][i0];
                    int d  = abs(ind - ind0);
                    int dist = dp[k-1][i0] + min(d, Nr - d);
                    min_dist = min(min_dist, dist);
                }
                dp[k][i] = min_dist;
            }
        }
        return *min_element(dp[Nk-1].begin(), dp[Nk-1].end()) + Nk;
    }
};
