// 2373. Largest Local Values in a Matrix
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> maxV(n-2, vector<int>(n));
        for (int i=0; i<n; i++)
            for (int j=0; j<n-2; j++)
                maxV[j][i] = *max_element(grid[i].begin()+j, grid[i].begin()+j+3);

        vector<vector<int>> result(n-2, vector<int>(n-2));
        for (int i=0; i<n-2; i++)
            for (int j=0; j<n-2; j++)
                result[j][i] = *max_element(maxV[i].begin()+j, maxV[i].begin()+j+3);
        
        return result;
    }
};
