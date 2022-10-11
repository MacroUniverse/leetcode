class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return maxN(nums.data(), nums.size(), k);
    }

    template <class T>
    int maxN(const T *v, int N, int Nmax)
    {
        typedef pair<T,int> P; // (val, ind)
        priority_queue<P, vector<P>, std::greater<P>> q;
        for (int i = 0; i < Nmax; ++i)
            q.push(P(v[i], i));
        for (int i = Nmax; i < N; ++i) {
            const T &val = v[i];
            if (val > q.top().first) {
                q.pop();
                q.push(P(val, i));
            }
        }
        return q.top().first;
    }
};
