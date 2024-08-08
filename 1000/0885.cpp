// 885. Spiral Matrix III
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        const int dirX[4] = {1, 0, -1, 0};
        const int dirY[4] = {0, 1, 0, -1};
        vector<vector<int>> result;
        for (int step=1, dir=0; result.size()<rows*cols; step++) {
            for (int i=0; i<2; i++) {
                for (int s=0; s<step; s++) {
                    if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                        result.push_back({rStart, cStart});
                    }
                    rStart += dirY[dir];
                    cStart += dirX[dir];
                }
                dir = (dir+1)%4;
            }
        }
        return result;
    }
};
