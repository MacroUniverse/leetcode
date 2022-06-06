class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<int> d;
        for (int i = 0; i < digits.size(); ++i)
            d.push_back(digits[i]-'2');
        int N = d.size();
        vector<string> dic = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        if (N == 0) return ret;
        string str; str.resize(N);
        if (N == 1) {
            string &sr = dic[d[0]];
            for (int i0 = 0; i0 < sr.size(); ++i0) {
                str[0] = sr[i0];
                ret.push_back(str);
            }
        }
        else if (N == 2) {
            string &sr = dic[d[0]];
            for (int i0 = 0; i0 < sr.size(); ++i0) {
                str[0] = sr[i0];
                string &sr = dic[d[1]];
                for (int i1 = 0; i1 < sr.size(); ++i1) {
                    str[1] = sr[i1];
                    ret.push_back(str);
                }
            }
        }
        else if (N == 3) {
            string &sr = dic[d[0]];
            for (int i0 = 0; i0 < sr.size(); ++i0) {
                str[0] = sr[i0];
                string &sr = dic[d[1]];
                for (int i1 = 0; i1 < sr.size(); ++i1) {
                    str[1] = sr[i1];
                    string &sr = dic[d[2]];
                    for (int i2 = 0; i2 < sr.size(); ++i2) {
                        str[2] = sr[i2];
                        ret.push_back(str);
                    }
                }
            }
        }
        else if (N == 4) {
            string &sr = dic[d[0]];
            for (int i0 = 0; i0 < sr.size(); ++i0) {
                str[0] = sr[i0];
                string &sr = dic[d[1]];
                for (int i1 = 0; i1 < sr.size(); ++i1) {
                    str[1] = sr[i1];
                    string &sr = dic[d[2]];
                    for (int i2 = 0; i2 < sr.size(); ++i2) {
                        str[2] = sr[i2];
                        string &sr = dic[d[3]];
                        for (int i3 = 0; i3 < sr.size(); ++i3) {
                            str[3] = sr[i3];
                            ret.push_back(str);
                        }
                    }
                }
            }
        }
        return ret;
    }
};
