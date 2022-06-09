class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1);
        num[0] = num[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += num[j]*num[i-j-1];
            }
            num[i] = sum;
        }
        return num.back();
    }
};

class Solution {
public:
    int numTrees(int n) {
        long C = 1;
        for (int i = 0; i < n; ++i) {
          C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int) C;
    }
};
