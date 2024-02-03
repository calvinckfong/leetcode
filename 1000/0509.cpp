// 509. Fibonacci Number
class Solution {
public:
    unordered_map<int, int> F;
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        if (F[n-2]==0)  F[n-2] = fib(n-2);
        if (F[n-1]==0)  F[n-1] = fib(n-1);
        return F[n-2] + F[n-1];
    }
};
