// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minute = -1, freshOrange=0, qsize;
        int x, y;

        queue<vector<int>> q;
        freshOrange = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j]==1)
                {
                    freshOrange++;
                }
            }
        }

        // No fresh orange
        if (freshOrange==0) return 0;

        // No rotton orange
        if (q.size()==0) return -1;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) // loop until no more rotten oranges
        {
            qsize = q.size();
            while (qsize--)
            {
                for (vector<int> dir: dirs)
                {
                    y = q.front()[0] + dir[0];
                    x = q.front()[1] + dir[1];

                    if (x<0 || y<0 || x>=n || y>=m || grid[y][x]!=1) continue;
                    grid[y][x] = 2;
                    q.push({y, x});
                    freshOrange--;
                }
                q.pop();
            }
            minute++;
        }
        return (freshOrange==0)?minute:-1;
    }
};
