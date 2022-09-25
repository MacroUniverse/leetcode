class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int i, j, N = intervals.size();
        vector<int> beg(N), end(N);
        for (i = 0; i < N; ++i)
            beg[i] = intervals[i][0],
            end[i] = intervals[i][1];
        sort(beg.begin(), beg.end());
        sort(end.begin(), end.end());
        int Nr = 0, Nr_max = 0; // current used rooms
        i = 0; j = 0;
        while (true) {
            if (beg[i] < end[j]) {
                Nr_max = max(Nr_max, ++Nr);
                if (++i == N) break;
            }
            else
                --Nr, ++j;
        }
        return Nr_max;
    }
};
