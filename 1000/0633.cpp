// 633. Sum of Square Numbers
class Solution {
public:
    bool judgeSquareSum(int c) {
        int rem, sqrt_rem=sqrt(c);
        for (int i=0; i<=sqrt(c/2); i++) {
            rem = c - i*i;
            sqrt_rem = sqrt(rem);
            if (sqrt_rem*sqrt_rem == rem) return true;
        }
        return false;
    }
};
