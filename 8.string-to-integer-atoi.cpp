class Solution {
public:
    int myAtoi(string str) {
        int N = str.size();
        bool negative = false;
        long long num = 0;
        bool got_sign = false;
        for (int i = 0; i < N; ++i) {
            char c = str[i];
            if (c == ' ') {
                if (got_sign)
                    break;
                continue;
            }
            else if (c == '+') {
                if (got_sign)
                    break;;
                got_sign = true;
                continue;
            }
            else if (c == '-') {
                if (got_sign)
                    break;
                negative = true;
                got_sign = true;
                continue;
            }
            else if (c < '0' || c > '9') {
                break;
            }
            if (!got_sign)
                got_sign = true;
            num = num*10 + (c - '0');
            if (negative) {
                if (-num < INT_MIN)
                    return INT_MIN;
            }
            else {
                if (num > INT_MAX)
                    return INT_MAX;
            }
                
            cout << num << endl;
        }
        if (negative)
            num = -num;
        return num;
    }
};
