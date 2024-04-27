// 514. Freedom Trail
class Solution {
public:
    int minStep;
    
    // record the indices of ring for each characters
    vector<int> mp[26];
    void buildMap(string& ring) {
        int n=ring.size();
        for (int i=0; i<n; i++) {
            mp[ring[i]-'a'].push_back(i);
        }
    }

    int rotateStep(string& key, int pos, int kIdx, int n, vector<vector<int>>& dp) {
        // end of key
        if (kIdx>=key.size()) {
            return 0;
        }
        // from pre-computed result
        if (dp[kIdx][pos]!=-1) {
            return dp[kIdx][pos];
        }

        int result=INT_MAX;
        char k = key[kIdx];

        // loop through all indices of the same character
        for (char next_pos: mp[k-'a']) {
            // next char in key
            int step = rotateStep(key, next_pos, kIdx+1, n, dp);
            if (step>result) continue;

            // find the best move between clockwise and anti-clockwise
            int mv_step = min(abs(next_pos-pos), n-abs(next_pos-pos));
            result = min(result, mv_step+step);
        }

        dp[kIdx][pos] = result;
        return result;
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        buildMap(ring);
        vector<vector<int>> dp(key.size(), vector<int>(ring.size(), -1));
        return rotateStep(key, 0, 0, n, dp) + key.size();
    }
};
