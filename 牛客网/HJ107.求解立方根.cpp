#include <iostream>
#include <cmath>
using namespace std;

inline double round01(double x) {
    return round(x * 10.) / 10.;
}

int main(void)
{
    double a,left = 0,right, mid, val;
    cin >> a;
    if (a == 0) {
        cout << 0 << endl; return 0;
    }
    int sgn = a > 0 ? 1 : -1;
    a = abs(a);
    right = a > 1 ? a : 1;
    while (round01(left) != round01(right)) {
        mid = (left + right) / 2;
        val = mid*mid*mid;
        if (val > a)
            right = mid;
        else if (val < a)
            left = mid;
        else {
            cout << round01(val); return 0;
        }
    }
    cout << sgn * round01(mid) << endl;
    return 0;
}
