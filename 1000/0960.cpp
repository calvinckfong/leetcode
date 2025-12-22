// 960. Delete Columns to Make Sorted III
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);

        for (int i=m-2; i>=0; i--) {
            for (int j=i+1; j<m; j++) {
                bool valid = true;
                for (auto& s: strs) {
                    if (s[i] > s[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        int res = 0;
        for (int& x: dp) {
            res = max(res, x);
        }
        return m - res;
    }
};
