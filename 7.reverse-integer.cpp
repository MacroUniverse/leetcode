class Solution {
public:
    int reverse(int x) {
        bool sign = true;
        if (x < 0) {
            sign = false;
            if (-(long long)x > INT_MAX)
                return 0;
            x = -x;
        }
        long long s = 0;
        while (x > 0) {
            s = 10*s + x % 10;
            if (s > INT_MAX)
                return 0;
            x /= 10;
            cout << s << endl;
        }
        if (!sign)
            s = -s;
        return (int)s;
    }
};
