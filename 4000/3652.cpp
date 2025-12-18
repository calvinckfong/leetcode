// 3652. Best Time to Buy and Sell Stock using Strategy
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profitSum(n+1);
        vector<long long> priceSum(n+1);
        for (int i=0; i<n; i++) {
            profitSum[i+1] = profitSum[i] + prices[i] * strategy[i];
            priceSum[i+1] = priceSum[i] + prices[i];
        }
        long long res = profitSum[n];
        for (int i=k-1; i<n; i++) {
            long long l = profitSum[i-k+1];
            long long r = profitSum[n] - profitSum[i+1];
            long long d = priceSum[i+1] - priceSum[i+1 -k/2];
            res = max(res, l + r + d);
        }
        return res;
    }
};
