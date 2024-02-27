// 762. Prime Number of Set Bits in Binary Representation
class Solution {
public:
    int countBit(int num)
    {
        int cnt = 0;
        printf("%d ", num);
        while (num) {
            if (num&1) cnt++;
            num/=2;
        }
        printf("%d\n", cnt);
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        vector<bool> isPrime(32, false);
        for (int i=0; i<primes.size(); i++)
            isPrime[primes[i]] = true;

        int bits, cnt=0;
        for (int i=left; i<=right; i++)
        {
            //bits = countBit(i);
            bits = __builtin_popcount(i); // __builtin_popcount() is much faster 
            if (isPrime[bits]) cnt++;
        }
        return cnt;
    }
};
