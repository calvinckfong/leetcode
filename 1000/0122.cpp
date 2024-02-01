// 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int n = prices.size();
        for (int i=0; i<n-1; i++)
            total_profit += max(0, prices[i+1] - prices[i]);

        return total_profit;
    }
};
