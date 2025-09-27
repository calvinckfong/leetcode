// 812. Largest Triangle Area
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n = p.size();
        int res = 0.0;
        for (int i=0; i<n-2; i++) {
            for (int j=i+1; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    res = max(res, 
                         abs((p[j][0]-p[i][0]) * (p[k][1]-p[i][1]) - 
                             (p[j][1]-p[i][1]) * (p[k][0]-p[i][0])));
                }
            }
        }
        return 0.5*res;
    }
};
