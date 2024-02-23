// 342. Power of Four
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return false;
        while (n>1) {
            if (n&3) return false;
            n/=4;
        }
        return true;
    }
};
