// 440. K-th Smallest in Lexicographical Order
class Solution {
public:
    int findKthNumber(int n, int k) {
        int ret=1, step;
        k--;
        while (k>0) {
            step = findStep(n, ret, ret+1);
            if (step <= k) {
                ret++;
                k -= step;
            } else {
                ret *= 10;
                k--;
            }
        }
        return ret;
    }

private:
    int findStep(long maxVal, long prefix1, long prefix2) {
        int ret = 0;
        while (prefix1 <= maxVal) {
            ret += min(maxVal+1, prefix2) - prefix1;
            // add 1 digit to prefix1 and prefix2
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return ret;
    }
};
