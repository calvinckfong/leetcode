// 3363. Find the Maximum Number of Fruits Collected
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res=0;
        n = fruits.size();
        for (int i=0; i<n; i++)
            res += fruits[i][i];

        res += dp(fruits);

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++)
                swap(fruits[j][i], fruits[i][j]);
        }

        res += dp(fruits);
        return res;
    }

private:
    int n;
    int dp(vector<vector<int>>& fruits) {
        vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
        prev[n-1] = fruits[0][n-1];
        for (int i=1; i<n-1; i++) {
            for (int j=max(n-1-i, i+1); j<n; j++) {
                int best = prev[j];
                if (j>=1) {
                    best = max(best, prev[j-1]);
                }

                if (j<n-1) {
                    best = max(best, prev[j+1]);
                }

                curr[j] = best + fruits[i][j];
            }
            swap(prev, curr);
        }
        return prev[n-1];
    }
};
