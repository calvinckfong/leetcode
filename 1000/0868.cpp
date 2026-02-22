// 868. Binary Gap
class Solution {
public:
    int binaryGap(int n) {
        int res = 0, l = -1;
        while ((n&1) == 0) n >>= 1;
        do {
            if (n&1) {
                res = max(res, l+1);
                l = 0;
            } else {
                l++;
            }
            n >>= 1;
        } while (n>0);
        return res;
    }
};
