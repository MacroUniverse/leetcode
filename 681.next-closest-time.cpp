class Solution {
public:
    string nextClosestTime(string time) {
        char i[4];
        i[0] = time[0] - '0'; i[1] = time[1] - '0';
        i[2] = time[3] - '0'; i[3] = time[4] - '0';
        int t0 = mins(i[0], i[1], i[2], i[3]);
        int min_dist = INT_MAX;
        for (auto i1 : i) {
            for (auto i2 : i) {
                if (i1*10+i2 > 23)
                    continue;
                for (auto i3 : i) {
                    for (auto i4 : i) {
                        if (i3*10+i4 > 59)
                            continue;
                        int dist = mins(i1, i2, i3, i4) - t0;
                        if (dist < 0) dist += 24*60;
                        if (dist == 0) continue;
                        if (dist < min_dist) {
                            min_dist = dist;
                            time[0] = i1+'0'; time[1] = i2+'0';
                            time[3] = i3+'0'; time[4] = i4+'0';
                        }
                    }
                }
            }
        }
        return time;
    }

    int mins(int i1, int i2, int i3, int i4) {
        return (i1*10+i2)*60 + i3*10+i4;
    }
};
