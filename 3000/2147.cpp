// 2147. Number of Ways to Divide a Long Corridor
class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int zero=0, one=0, two=1;

        for (char c: corridor) {
            if (c == 'S') {
                zero = one;
                swap(one, two);
            } else {
                two = (two + zero) % MOD;
            }
        }
        return zero;
    }
};
