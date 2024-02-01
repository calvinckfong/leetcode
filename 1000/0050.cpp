// 50. Pow(x, n)
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long m = abs(n);

        while (m>0)
        {
            if (m%2) res *= x;
            
            x *= x;
            m/=2;
        }

        return (n<0)?(1.0/res):res;
    }
};
