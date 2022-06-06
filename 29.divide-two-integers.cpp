class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int x = abs(dividend), y = abs(divisor);
        bool negative = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            negative = true;
        int pow = 0, ret = 0;
        if (x == y)
            return negative?-1:1;
        else if (dividend == -2147483648 && y == 1)
            return negative?-2147483648:2147483647;
        while (x > y) {
            y <<= 1; ++pow;
        }
        while (pow > 0) {
            y >>= 1; --pow;
            if (x >= y) {
                x -= y; ret += (1 << pow);
            }
        }
        if (x == y) {
            x -= y; ret += 1;
        }
        if (negative)
            ret = -ret;
        return ret;
    }
};
