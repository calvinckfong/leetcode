// 1137. N-th Tribonacci Number
class Solution {
public:
    int T[38];  // max(n) = 37
    int tribonacci(int n) {
        if (n==0)   { return 0; }
        if (n<3)   { return 1; }
        
        T[0] = 0; T[1] = 1; T[2] = 1;
        if (!T[n-1])
            T[n-1] = tribonacci(n-1);

        return T[n-1] + T[n-2] + T[n-3];
    }
};
