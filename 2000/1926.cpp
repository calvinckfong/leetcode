// 1926. Nearest Exit from Entrance in Maze
class Solution {
public:
    int m, n;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();

        queue<array<int, 3>> q; // for bfs
        q.push({entrance[0], entrance[1], 0});

        // bfs
        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {
                auto [y, x, step] = q.front(); q.pop();

                bool isEntrance = (x==entrance[1] && y==entrance[0]);
                bool isBorder = (x==0 || x==n-1 || y==0 || y==m-1);
                if (isBorder && !isEntrance) return step;

                step++;
                if (x>0   && maze[y][x-1]=='.') {q.push({y, x-1, step}); maze[y][x-1] = '+';}
                if (x<n-1 && maze[y][x+1]=='.') {q.push({y, x+1, step}); maze[y][x+1] = '+';}
                if (y>0   && maze[y-1][x]=='.') {q.push({y-1, x, step}); maze[y-1][x] = '+';}
                if (y<m-1 && maze[y+1][x]=='.') {q.push({y+1, x, step}); maze[y+1][x] = '+';}
            }
        }

        return -1;
    }
};
