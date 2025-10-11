// 3186. Maximum Total Damage With Spell Casting
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> cnt;
        for (int p: power) {
            cnt[p]++;
        }

        vector<int> keys;
        for (auto& [k,_]: cnt) {
            keys.push_back(k);
        }
        sort(keys.begin(), keys.end());
        int n = keys.size();

        vector<long long> dp(n);
        dp[0] = (long long)(cnt[keys[0]]) * keys[0];
        for (int i=1; i<n; i++) {
            long long curr = cnt[keys[i]] * keys[i];
            int prev = upper_bound(keys.begin(), keys.begin()+i, keys[i]-3) - keys.begin() - 1;
            if (prev>=0) curr += dp[prev];
            dp[i] = max(dp[i-1], curr);
        }
        return dp[n-1];
    }
};
