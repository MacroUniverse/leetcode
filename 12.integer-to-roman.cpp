class Solution {
public:
    string intToRoman(int num) {
        string ret;
        vector<string> sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int ind = 0;
        while (num > 0) {
            while (num >= val[ind]) {
                num -= val[ind];
                ret += sym[ind];
            }
            ++ind;
        }
        return ret;
    }
};
