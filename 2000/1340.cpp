// 1340. Jump Game V
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n, -1);
        int res = 0;
        for (int i=0; i<n; i++) {
            res = max(res, solve(arr, i, d));
        }
        return res;
    }

public:
    int n;
    vector<int> dp;

    int solve(vector<int>& arr, int i, int d) {
        if (dp[i] != -1) return dp[i];

        dp[i] = 1;
        for (int j=i-1; j>=0 && i-j<=d && arr[i]>arr[j]; j--) {
            int tmp = solve(arr, j, d);
            dp[i] = max(dp[i], tmp+1);
        }
        for (int j=i+1; j<n && j-i<=d && arr[i]>arr[j]; j++) {
            int tmp = solve(arr, j, d);
            dp[i] = max(dp[i], tmp+1);
        }

        return dp[i];
    }
};
