// 624. Maximum Distance in Arrays
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int n = arrays[0].size();
        int minVal = arrays[0][0];
        int maxVal = arrays[0][n-1];
        int minV, maxV, result = 0;
        for (int i=1; i<m; i++) {
            n = arrays[i].size();
            minV = arrays[i][0];
            maxV = arrays[i][n-1];
            result = max(result, maxVal-minV);
            result = max(result, maxV-minVal);
            maxVal = max(maxVal, maxV);
            minVal = min(minVal, minV);
        }
        return result;
    }
};
