// 172. Factorial Trailing Zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        int nZero = 0, j;
        for(int i=5; i<=n; i+=5)
        {
            j = i;
            while (j%5==0)
            {
                nZero++;
                j/=5;
            }
        }
        return nZero;
    }
};
