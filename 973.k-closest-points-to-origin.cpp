class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret(k, vector<int>(2));
        maxN(ret, points, k);
        return ret;
    }

    inline void maxN(vector<vector<int>> &ret, vector<vector<int>>& pt, int Nmax)
    {
        int N = pt.size();
        typedef pair<int,int> P; // (val, ind)
        priority_queue<P, vector<P>, std::greater<P>> q;
        for (int i = 0; i < Nmax; ++i)
            q.push(P(dist(pt[i]), i));
        for (int i = Nmax; i < N; ++i) {
            int val = dist(pt[i]);
            if (val > q.top().first) {
                q.pop();
                q.push(P(val, i));
            }
        }
        for (int i = 0; i < Nmax; ++i) {
            int j = Nmax-i-1;
            ret[j] = pt[q.top().second];
            q.pop();
        }
    }

    int dist(const vector<int> &p)
    {
        int x = p[0], y = p[1];
        return -x*x - y*y;
    }
};
