// 3494. Find the Minimum Amount of Time to Brew Potions
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> res(n);
        for (int mn : mana) {
            long long currTime = 0;
            for (int i=0; i<n; i++) {
                currTime = max(currTime, res[i]) + skill[i]*mn;
            }
            res[n - 1] = currTime;
            for (int i=n-2; i>=0; i--) {
                res[i] = res[i+1] - skill[i+1]*mn;
            }
        }
        return res[n-1];
    }
};
