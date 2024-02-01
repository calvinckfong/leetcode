// 69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        int lo=0, hi=x;
        if (x<2) return x;
        long long mid, r, y=(long long)(x);
        while (hi-lo>1)
        {
            mid = lo + (hi-lo)/2;
            r = mid * mid;
            if (r==y) return int(mid);
            else if (r<y) lo = mid;
            else hi = mid; 
        }
        return lo;
    }
};
