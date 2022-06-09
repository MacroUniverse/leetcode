class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        auto comp = [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), comp);
        int N = intervals.size();
        int pair[2];
        int b0 = intervals[0][0], e0 = intervals[0][1];
        for (int i = 1; i < N; ++i) {
            int b = intervals[i][0], e = intervals[i][1];
            if (b > e0) {
                ret.push_back({b0, e0});
                b0 = b; e0 = e;
            }
            else {
                if (e > e0)
                    e0 = e;
            }
        }
        ret.push_back({b0, e0});
        return ret;
    }
};
