// 552. Student Attendance Record II
class Solution {
public:
    int dp[100001][2][3];
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, false, 0, n);
    }

private:
    int solve(int i, bool absent, int lateCnt, int n) {
        if (i==n) return 1;

        if (dp[i][absent][lateCnt] != -1)
            return dp[i][absent][lateCnt];

        const int mod = 1000000007;
        if (!absent) 
        {
            int numA = solve(i+1, true, 0, n);
            int numL = (lateCnt!=2)?solve(i+1, false, lateCnt+1, n):0;
            int numP = solve(i+1, false, 0, n);

            return dp[i][absent][lateCnt] = ((numA+numL) % mod + numP) % mod;
        }

        int numL = (lateCnt!=2)?solve(i+1, true, lateCnt+1, n):0;
        int numP = solve(i+1, true, 0, n);

        return dp[i][absent][lateCnt] = (numL+numP) % mod;
    }
};
