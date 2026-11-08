// 1267. Count Servers that Communicate
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int maxN = 250;
        int m = grid.size(), n = grid[0].size();

        vector<int> rowCnt(m, 0);
        vector<int> colCnt(n, 0);

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        int res = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    res += (rowCnt[i]>1 || colCnt[j]>1);
                }   
            }
        }

        return res;
    }
};
