// 3946. Maximum Number of Items From Sale I
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> dp(budget+1, 0);
        int minp = INT_MAX;
        for (auto& item: items) {
            int factor = item[0], price = item[1];
            minp = min(minp, price);
            int cnt = 0;
            for (auto& x: items) {
                if (x[0] % factor == 0) cnt++;
            }
            for (int i=budget; i>=price; i--) {
                dp[i] = max(dp[i], dp[i-price]+cnt);
            }
        }

        int res = 0;
        for (int i=0; i<=budget; i++) {
            res = max(res, dp[i] + (budget-i)/minp);
        }
        return res;
    }
};
