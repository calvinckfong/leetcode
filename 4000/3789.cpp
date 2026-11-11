// 3789. Minimum Cost to Acquire Required Items
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res = 0;

        if (cost1+cost2 <= costBoth) {
            res = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        } else {
            int cnt = min(need1, need2);
            res = 1LL * cnt * costBoth;

            need1 -= cnt;
            need2 -= cnt;

            if (need1>0) 
                res += 1LL * need1 * min(cost1, costBoth);
            else if (need2>0) 
                res += 1LL * need2 * min(cost2, costBoth);
        }

        return res;
    }
};
