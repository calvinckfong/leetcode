// 2523. Closest Prime Numbers in Range
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> isPrime = findPrimes(right);
        vector<int> primes, result(2);
        for (int i=left; i<=right; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
        if (primes.size()<2) return {-1, -1};

        int minDiff = INT_MAX;
        for (int i=1; i<primes.size(); i++) {
            int diff = primes[i]-primes[i-1];
            if (diff<minDiff) {
                minDiff = diff;
                result[0] = primes[i-1];
                result[1] = primes[i];
            }
        }
        return result;
    }

private:
    vector<int> findPrimes(int right) {
        vector<int> result(right+1, 1);
        result[0] = 0;
        result[1] = 0;
        for (int i=0; i*i<=right; i++) {
            if (result[i]==1) {
                for (int k=i*i; k<=right; k+=i)
                    result[k] = 0;
            }
        }
        return result;
    }
};
