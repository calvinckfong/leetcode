// 231. Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // count number of 1 in binary format
        if (n<1) return false;
        int cnt = 0;
        while (n)
        {
            cnt += (n&1);
            if (cnt>1) return false;
            n/=2;
        }
        return (cnt==1);
    }
};
