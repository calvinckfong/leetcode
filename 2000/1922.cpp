// 1922. Count Good Numbers
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        return (long long)power(5, (n+1)/2) * power(4, n/2) % MOD;;
    }

private:
    int power(int base, long long exp) {
        int result = 1, mul = base;
        while (exp > 0) {
            if (exp%2) result = (long long) mul * result % MOD;
            mul = (long long) mul * mul % MOD;
            exp /= 2;
        }
        return result;
    }
};
