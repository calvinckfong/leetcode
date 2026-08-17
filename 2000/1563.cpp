// 1563. Stone Game V
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> f(n, vector<int>(n));
        vector<vector<int>> maxl(n, vector<int>(n));
        vector<vector<int>> maxr(n, vector<int>(n));

        for (int l=n-1; l>=0; l--) {
            maxl[l][l] = maxr[l][l] = stoneValue[l];
            int sum = stoneValue[l], suml = 0;
            for (int r=l+1, i=l-1; r<n; r++) {
                sum += stoneValue[r];
                while (i+1<r && (suml+stoneValue[i+1])*2<=sum) {
                    suml += stoneValue[i+1];
                    i++;
                }
                if (l<=i)   f[l][r] = max(f[l][r], maxl[l][i]);
                if (i+1<r)  f[l][r] = max(f[l][r], maxr[i+2][r]);
                if (suml*2==sum) f[l][r] = max(f[l][r], maxr[i+1][r]);
                maxl[l][r] = max(maxl[l][r-1], sum+f[l][r]);
                maxr[l][r] = max(maxr[l+1][r], sum+f[l][r]);
            }
        }
        return f[0][n-1];
    }
};
