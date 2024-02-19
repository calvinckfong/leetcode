// 204. Count Primes
class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool> isPrime(n, true);
        if (n>2) cnt++; // handle special case `2`

        // loop all odd numbers
        for (int i=3; i<n; i+=2)
        {
            // next number if it is marked as non-prime
            if (!isPrime[i]) continue;
            
            cnt++;
            
            // mark all multiples of i less than n to non-prime
            for (int j=i; j<n; j+=i)
                isPrime[j] = false;
        }
        return cnt;
    }
};
