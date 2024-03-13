// 2485. Find the Pivot Integer
class Solution {
public:
    int pivotInteger(int n) {
        int lsum=0, rsum=0;
        for (int i=1; i<=n; i++)    rsum+= i;
        for (int i=1; i<=n; i++)
        {
            lsum += i;
            if (lsum==rsum) return i;
            if (lsum>rsum) break;
            rsum -= i;
        }
        return -1;
    }
};
