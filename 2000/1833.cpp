// 1833. Maximum Ice Cream Bars
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int i=0; i<costs.size() && coins>0; i++) {
            if (coins >= costs[i]) {
                res ++;
                coins -= costs[i];
            } 
        }
        return res;
    }
};
