class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] != ')')
                ++i;
            if (i == n)
                break;
            int j = i-1;
            while (j >= 0 && s[j] != '(')
                --j;
            reverse(s.begin()+j+1, s.begin()+i);
            s.erase(s.begin()+i);
            s.erase(s.begin()+j);
            n -= 2;
            i -= 2;
        }
        return s;
    }
};
