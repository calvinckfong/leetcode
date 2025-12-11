// 3531. Count Covered Buildings
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int n1 = n+1;
        vector<int> maxR(n1);
        vector<int> minR(n1, n1);
        vector<int> maxC(n1);
        vector<int> minC(n1, n1);

        for (auto& p: buildings) {
            int x = p[0], y = p[1];
            maxR[y] = max(maxR[y], x);
            minR[y] = min(minR[y], x);
            maxC[x] = max(maxC[x], y);
            minC[x] = min(minC[x], y);
        }

        int res = 0;
        for (auto& p: buildings) {
            int x = p[0], y = p[1];
            res += (x>minR[y] && x<maxR[y] && y>minC[x] && y<maxC[x]);
        }
        return res;
    }
};
