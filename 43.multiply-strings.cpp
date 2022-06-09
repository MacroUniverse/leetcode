class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ret(num1.size() + num2.size(), '0');
        for (int j = 0; j < num2.size(); ++j) {
            char d2 = num2[j] - '0';
            for (int i = 0; i < num1.size(); ++i) {
                char d1 = num1[i] - '0';
                int ind = i + j;
                char prod = (ret[ind] - '0') + d1 * d2;
                ret[ind] = prod % char(10) + '0';
                ret[ind+1] += prod / char(10);
            }
        }
        if (ret.back() == '0')
            ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
