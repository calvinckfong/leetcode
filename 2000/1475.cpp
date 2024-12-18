// 1475. Final Prices With a Special Discount in a Shop
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        for (int i=0; i<n; i++) {
            int p = prices[i];
            for (int j=i+1; j<n; j++) {
                if (prices[j]<=p) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};
