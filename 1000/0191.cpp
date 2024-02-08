// 191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n)
        {
            result += (n&1);
            n >>= 1;
        }
        return result;
    }
};
