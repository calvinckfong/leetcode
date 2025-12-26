// 2483. Minimum Penalty for a Shop
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minP = 0, currP = 0;
        int res = 0;

        for (int i=0; i<n; i++) {
            if (customers[i] == 'Y')
                currP--;
            else
                currP++;

            if (currP < minP) {
                res = i+1;
                minP = currP;
            }
        }
        return res;
    }
};
