class Solution {
public:
    string getPermutation(int n, int k) {
        string v; v.resize(n);
        for (int i = 0; i < n; ++i)
            v[i] = '1' + i;
        helper(v, n, k-1);
        return v;
    }
    
    void helper(string &v, int n, int k) {
        if (k == 0) return;
        int i, ifac = 1;
        for (i = 2; i <=n; ++i) {
            ifac *= i;
            if (k < ifac)
                break;
        }
        char *p = &v[0] + n - i;
        if (k == ifac-1) {
            reverse(p, p+i);
            return;
        }
        int im1fac = ifac/i;
        int ind = k / im1fac;
        swap(*p, *(p+ind));
        sort(p+1, p+i);
        helper(v, n, k % im1fac);
    }
};
