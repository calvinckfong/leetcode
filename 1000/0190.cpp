// 190. Reverse Bits
class Solution {
public:
    int reverseBits(int n) {
        if (!n) return n;
        int result=0, i=31;
        for (; i>=0 && n>0; i--)
        {
            result <<= 1;
            result |= (n&1);
            n>>=1;
        }
        return result<<(i+1);
    }
};
