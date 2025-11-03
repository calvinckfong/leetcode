// 1578. Minimum Time to Make Rope Colorful
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int maxC, sumC, res = 0;
        maxC = sumC = neededTime[0];
        for (int i=1; i<n; i++) {
            if (colors[i] != colors[i-1]) {
                res += sumC - maxC;
                sumC = maxC = 0;
            }
            sumC += neededTime[i];
            maxC = max(maxC, neededTime[i]);
        }
        res += sumC - maxC;
        return res;
    }
};
