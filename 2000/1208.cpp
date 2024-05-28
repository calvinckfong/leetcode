// 1208. Get Equal Substrings Within Budget
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cost(n);
        for (int i=0; i<n; i++)
            cost[i] = abs(s[i] - t[i]);

        int result = 0, l=0, r=0;
        int totalCost = 0;
        while (r<n) {
            if (totalCost + cost[r] <= maxCost) {
                totalCost += cost[r++];
                result = max(result, r-l);
            } else {
                totalCost -= cost[l++];
            }
        }
        return result;
    }
};
