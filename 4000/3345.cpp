// 3345. Smallest Divisible Digit Product I
class Solution {
public:
    int smallestNumber(int n, int t) {
        while (!check(n, t))
            n++;
        return n;
    }

private:
    bool check(int n, int t) {
        int prod = 1;
        while (n>0) {
            prod *= n%10;
            n /= 10;
            if ((prod%t) == 0)
                return true;
        } 
        return false;
    }
};
