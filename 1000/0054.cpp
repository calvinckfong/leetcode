// 54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int delta_x[4] = {1, 0, -1, 0};
        int delta_y[4] = {0, 1, 0, -1};
        int direction = 0;
        int nrows = matrix.size();
        int ncols = matrix[0].size();

        int cnt=0, x=0, y=0;
        vector<int> ret(nrows*ncols);
        while (cnt<nrows*ncols)
        {
            ret[cnt++] = matrix[y][x];
            matrix[y][x] = -999;    // mark it as visisted(-999)
            x += delta_x[direction];
            y += delta_y[direction];

            // if out of boundary or visited cell
            if (x>=ncols || x<0 || y>=nrows || y<0 || matrix[y][x] == -999)
            {
                // step back 1 time
                x -= delta_x[direction];
                y -= delta_y[direction];
                // change direction
                direction = (direction+1)%4;
                // step forward 1 time
                x += delta_x[direction];
                y += delta_y[direction];
            }
        }
        return ret;
    }
};
