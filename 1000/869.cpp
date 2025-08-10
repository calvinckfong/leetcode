// 869. Reordered Power of 2
class Solution {
public:
bool reorderedPowerOf2(int n) {
        long re = counter(n);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == re) return true;
        return false;
    }

    long counter(int N) {
        long res = 0;
        for (; N; N/=10) res += pow(10, N%10);
        return res;
    }
};
