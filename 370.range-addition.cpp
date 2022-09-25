// very slow
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret(length, 0);
        for (auto &e : updates) {
            int e1 = e[1], e2 = e[2];
            for (int i = e[0]; i <= e1; ++i)
                ret[i] += e2;
        }
        return ret;
    }
};

// very fast
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		// this is actually ret[i]-ret[i-1] with ret[-1] = 0
        vector<int> v(length, 0);
        for (auto &e : updates) {
            int e11 = e[1]+1, e2 = e[2];
            v[e[0]] += e2;
            if (e11 < length)
                v[e11] -= e2;
        }
        for (int i = 1; i < length; ++i)
            v[i] += v[i-1];
        return v;
    }
};
