// 3871. Count Commas in Range II
class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long t = 1000;
        while (t<=n) {
            res += (n-t+1);
            t *= 1000;
        }
        return res;
    }
};
