// 1510. Stone Game IV
class Solution {
public:
    bool winnerSquareGame(int n) {
        return dp.test(n);
    }

private:
    static const int MAX_N = 1e5 + 1;
    inline static bitset<MAX_N> dp;

    inline static bool init = []() {
        for (int i=0; i<MAX_N; i++) {
            if (dp.test(i)) continue;
            for (int j=1; j*j<MAX_N-i; j++) {
                dp.set(i+j*j);
            }
        }
        return false;
    }();
};
