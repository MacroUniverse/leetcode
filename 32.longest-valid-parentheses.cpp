class Solution {
public:
    int longestValidParentheses(string s) {
        int Nmax = 0;
        vector<int> stack;
        stack.push_back(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                stack.pop_back();
                if (stack.empty())
                    stack.push_back(i);
                else
                    Nmax = max(Nmax, i - stack.back());
            }
        }
        return Nmax;
    }
};
