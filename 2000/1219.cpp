// 1219. Path with Maximum Gold
class Solution {
public:
    int m, n;
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int result=0;
        // Loop through all cell as starting point
        // collect the gold
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int amount = getGold(grid, i, j, 0);
                result = max(result, amount);
            }
        }
        return result;
    }
private:
    int getGold(vector<vector<int>>& grid, int i, int j, int amount) {
        if (grid[i][j]==0) return amount;
        int lastAmount = grid[i][j];
        int maxAmount = amount+lastAmount;
        grid[i][j]=0;
        
        if (i>0)    maxAmount = max(maxAmount, getGold(grid, i-1, j, amount+lastAmount));
        if (i<m-1)  maxAmount = max(maxAmount, getGold(grid, i+1, j, amount+lastAmount));
        if (j>0)    maxAmount = max(maxAmount, getGold(grid, i, j-1, amount+lastAmount));
        if (j<n-1)  maxAmount = max(maxAmount, getGold(grid, i, j+1, amount+lastAmount));

        grid[i][j]=lastAmount;
        return maxAmount;
    }
};
