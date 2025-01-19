// 407. Trapping Rain Water II
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int dirs[5] = {-1, 0, 1, 0, -1};
        m = heightMap.size(), n = heightMap[0].size();
        if (m<=2 || n<=2) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n));
        typedef pair<int, pair<int, int>> Cell;
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        for (int i=0; i<m; i++) {
            pq.push({heightMap[i][0]  , {i, 0  }});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }

        for (int i=0; i<n; i++) {
            pq.push({heightMap[0  ][i], {0,   i}});
            pq.push({heightMap[m-1][i], {m-1, i}});
            visited[0][i] = visited[m-1][i] = true;
        }

        int result = 0;
        while (!pq.empty()) {
            Cell curr = pq.top();
            pq.pop();

            int currH = curr.first;
            int currR = curr.second.first;
            int currC = curr.second.second;
            
            for (int i=0; i<4; i++) {
                int nextR = currR + dirs[i];
                int nextC = currC + dirs[i+1];
                if (isValid(nextR, nextC) && !visited[nextR][nextC]) {
                    int nextH = heightMap[nextR][nextC];
                    if (nextH < currH)
                        result += currH - nextH;
                    pq.push({max(nextH, currH), {nextR, nextC}});
                    visited[nextR][nextC] = true;
                }
            }
        }
        return result;
    }

private:
    int m, n;
    bool isValid(int r, int c) {
        return r>=0 && r<m && c>=0 && c<n;
    }
};
