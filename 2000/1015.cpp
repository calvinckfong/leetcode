// 1015. Smallest Integer Divisible by K
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;
        if (k%2 == 0) return -1;
        if (k%5 == 0) return -1;
        int res = 1, n = 1;
        while (n) {
            n = (n*10 + 1) % k;
            res++;
        } 
        return res;
    }
};
