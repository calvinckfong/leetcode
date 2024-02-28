// 1037. Valid Boomerang
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // area of triangle = 0.5 * abs(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))
        int a1 = points[0][0]*(points[1][1] - points[2][1]);
        int a2 = points[1][0]*(points[2][1] - points[0][1]);
        int a3 = points[2][0]*(points[0][1] - points[1][1]);
        return (a1+a2+a3!=0);
    }
};
