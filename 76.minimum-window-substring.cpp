class Solution {
public:
    string minWindow(string s, string t) {
        int L = 0, R = 0, Lmin = 0, Rmin = s.size(), rem = t.size();
        unordered_map<char, int> m;
        for (char c: t) m.count(c) ? ++m[c] : (m[c] = 1);
        while (R < s.size()) {
            while (R < s.size() && rem > 0) {
                if (m.count(s[R]) && m[s[R]]-- > 0) --rem;
                ++R;
            }
            while (L < R && rem == 0) {
                if (R - L < Rmin - Lmin) Rmin = R, Lmin = L;
                if (m.count(s[L]) && m[s[L]]++ == 0) ++rem;
                ++L;
            }
        }
        return L ? s.substr(Lmin, Rmin-Lmin) : "";
    }
};
