// 3370. Smallest Number With All Set Bits
class Solution {
public:
    int smallestNumber(int n) {
        int res = 0, i = 0;
        while (n>0) {
            res += (1<<i++);
            n>>=1;
        }
        return res;
    }
};
