// 231. Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // count number of 1 in binary format
        if (n<1) return false;
        int cnt = n&1;
        while (n>>=1)
        {
            cnt += (n&1);
            if (cnt>1) return false;
        }
        return true;
    }
};
