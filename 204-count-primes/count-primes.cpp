class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        // Only store odd numbers
        vector<bool> isPrime(n / 2, true);

        // 0 represents number 1, which is not prime
        isPrime[0] = false;

        // i represents actual number = 2*i + 1
        for (int i = 3; i * i < n; i += 2) {

            if (isPrime[i / 2]) {

                // Start from i*i
                for (long long j = 1LL * i * i; j < n; j += 2 * i) {
                    isPrime[j / 2] = false;
                }
            }
        }

        int count = 1; // prime number 2

        // Check odd numbers
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i / 2])
                count++;
        }

        return count;
    }
};