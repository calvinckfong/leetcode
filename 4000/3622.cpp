// 3622. Check Divisibility by Digit Sum and Product
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1, tmp=n;
        while (tmp) {
            int d = tmp %10;
            sum += d;
            prod *= d;
            tmp /= 10;
        }
        return (n % (sum+prod) == 0);
    }
};
