// 1905. Count Sub Islands
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        int result = 0;
        
        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                if (grid2[y][x]>0) {
                    grid2[y][x] *= -1;
                    result += isSubIsland(x, y, grid1, grid2);
                }
            }
        }

        return result;
    }

private:
    int directions[5] = {1, 0, -1, 0, 1};

    bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        bool result = true;

        if (grid1[y][x]==0)
            result = false;

        for (int i=0; i<4; i++) {
            int xx = x + directions[i];
            int yy = y + directions[i+1];

            if (xx>=0 && yy>=0 && xx<n && yy<m && grid2[yy][xx]>0) {
                grid2[yy][xx] *= -1;
                bool sameSubIsland = isSubIsland(xx, yy, grid1, grid2);
                result &= sameSubIsland;
            }
        }

        return result;
    }
};
