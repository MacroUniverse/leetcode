class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1)
            return x;
        else if (x == -1)
            if (n % 2 == 0)
                return 1;
            else
                return -1;
        
        
        if (n < 0) {
			if (n == -2147483648) {
            	x = 1/(x*x); n = 1073741824;
        	}
			else {
            	x = 1/x; n = -n;
			}
        }
        double ans = 1, mul = x;
        while (1) {
            if (n % 2 == 1) {
                ans *= mul;
                if (ans == 0)
                    return ans;
            }
            n /= 2;
            if (n == 0)
                return ans;
            mul = mul*mul;
        }
    }
};
