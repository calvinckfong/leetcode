// 3546. Equal Sum Grid Partition I
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for (auto& row: grid) {
            total += accumulate(row.begin(), row.end(), 0LL);
        }

        if (total&1) return false;
        long long target = total/2;
        int m = grid.size(), n = grid[0].size();
        
        long long rSum=0, cSum=0;
        for (int i=0; i<m && rSum<target; i++) {
            rSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }
        if (rSum==target) return true;

        for (int i=0; i<n && cSum<target; i++) {
            for (int j=0; j<m; j++) cSum += grid[j][i];
        }
        return (cSum==target);
    }
};
