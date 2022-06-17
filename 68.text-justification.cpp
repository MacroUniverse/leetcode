class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int N1 = words[0].size(), i0 = 0;
        ret.push_back(words[0]);
        for (int i = 1; i < words.size(); ++i) {
            int tmp = N1 + 1 + words[i].size();
            if (tmp > maxWidth) {
                int Nsp = i - i0 - 1;
                int Nsp_add = maxWidth - N1;
                if (Nsp == 0)
                    ret.back() += string(Nsp_add, ' ');
                else {
                    int Nsp1 = Nsp_add / Nsp + 1, rem = Nsp_add % Nsp;
                    for (int i = 1; i <= rem; ++i)
                        ret.back() += string(Nsp1+1, ' ') + words[i0+i];
                    for (int i = rem+1; i <= Nsp; ++i)
                        ret.back() += string(Nsp1, ' ') + words[i0+i];
                }
                i0 = i; N1 = words[i].size();
                ret.emplace_back(); ret.back() += words[i];
                continue;
            }
            else
                N1 = tmp;
        }
        for (int i = i0 + 1; i < words.size(); ++i)
            ret.back() += " " + words[i];
        if (ret.back().size() < maxWidth)
            ret.back() += string(maxWidth - ret.back().size(), ' ');
        return ret;
    }
};
