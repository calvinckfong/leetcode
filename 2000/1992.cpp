// 1992. Find All Groups of Farmland
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m=land.size(), n=land[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (land[i][j]==1) { // check if it is farmland
                    int h=i, w=j;
                    // find width and height of the land
                    while (h<m && land[h][j]==1) h++;
                    while (w<n && land[i][w]==1) w++;
                    // add to result
                    result.push_back({i, j, h-1, w-1});
                    // clear the land
                    for (int u=i; u<h; u++) {
                        for (int v=j; v<w; v++) {
                            land[u][v] = 0;
                        }
                    }
                }
            }
        }
        return result;
    }
};
