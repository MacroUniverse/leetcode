class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> ret(N); ret.back() = 0;
        for (int i = N-2; i >= 0; --i) {
            int ind = 1;
            while (1) {
                if (temperatures[i] < temperatures[i+ind]) {
                    ret[i] = ind; break;
                }
                if (ret[i+ind])
                    ind += ret[i+ind];
                else {
                    ret[i] = 0; break;
                }
            }
        }
        return ret;
    }
};
