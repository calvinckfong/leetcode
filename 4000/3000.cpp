// 3000. Maximum Area of Longest Diagonal Rectangle
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diag = 0, res;
        for (auto& it:dimensions)
        {
            int w = it[0], h= it[1];
            int diag = w*w + h*h;
            if (diag > max_diag)
            {
                max_diag = diag;
                res = w*h;
            }
            else if (diag == max_diag)
            {
                res = max(res, w*h);
            }
        }

        return res;
    }
};
