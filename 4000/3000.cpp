// 3000. Maximum Area of Longest Diagonal Rectangle
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diag = 0, diag, area;
        int w, h;
        for (auto it:dimensions)
        {
            w = it[0]; h= it[1];
            diag = w*w + h*h;
            if (diag > max_diag)
            {
                max_diag = diag;
                area = w*h;
            }
            else if (diag == max_diag)
            {
                area = max(area, w*h);
            }
        }

        return area;
    }
};
