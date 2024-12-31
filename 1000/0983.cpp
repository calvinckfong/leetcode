// 983. Minimum Cost For Tickets
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last = days[days.size()-1];
        vector<int> dp(last+1);

        int curr=0;
        for (int i=1; i<=last; i++) {
            if (i < days[curr]) {
                dp[i] = dp[i-1];
            } else {
                curr++;
                dp[i] = min ({
                    dp[i-1] + costs[0],
                    dp[max(i-7, 0)] + costs[1],
                    dp[max(i-30, 0)] + costs[2]});
            }
        }
        return dp[last];
    }
};
