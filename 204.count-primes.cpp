class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        if (n <= 2) return 0;
        if (n <= 3) return 1;
        int n2 = n/2 + 1;
        for (int i = 2; i < n2; ++i) {
            if (isPrime[i])
                primes.push_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0)
                    break;
            }
        }
        int N = primes.size();
        for (int i = n2; i < n; ++i)
            if (isPrime[i])
                ++N;
        return N;
    }
};

// solution 2 95%

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n <= 3) return 1;
        vector<bool> pno(n, true);
        for (int i = 2; i*i < n; i++) {
            if (pno[i]) {
                for (int j = i*2; j < n; j += i)
                    pno[j] = false;
            }
        }
        int N = 0;
        for (int i = 2; i < n; i++)
            if (pno[i])
                ++N;
        return N;
    }
};
