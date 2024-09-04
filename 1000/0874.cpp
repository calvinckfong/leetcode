// 874. Walking Robot Simulation
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0, y=0, maxD=0;
        int dir=0, nx, ny;
        const int d[] = {0, 1, 0, -1, 0};
        const int W = 2*3e4 + 1;
        unordered_set<int> obsSet;
        for (auto& p: obstacles)
            obsSet.insert(p[1]*W+p[0]);
        
        for (int c: commands) {
            if (c == -1) {
                dir = (dir + 1) % 4;
                continue;
            } else if (c == -2) {
                dir = (dir + 3) % 4;
                continue;
            } else {
                while (c>0) {
                    nx = x + d[dir];
                    ny = y + d[dir+1]; 
                    if (obsSet.contains(ny*W+nx))
                        break;
                    x = nx;
                    y = ny;
                    c--;
                }
                maxD = max(maxD, x*x+y*y);
            }
        }

        return maxD;
    }
};
