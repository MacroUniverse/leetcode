class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        vector<int> rem(N+1);
        rem[0] = 0;
        for (int i = 0; i < N; ++i) {
            rem[i+1] = rem[i] + gas[i] - cost[i];
        }
        if (rem[N] < 0)
            return -1;
        return min_element(rem.begin(), rem.end()) - rem.begin();
    }
};
