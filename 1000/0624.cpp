// 624. Maximum Distance in Arrays
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int minVal = *min_element(arrays[0].begin(), arrays[0].end());
        int maxVal = *max_element(arrays[0].begin(), arrays[0].end());
        int minV, maxV, result = 0;
        for (int i=1; i<m; i++) {
            minV = *min_element(arrays[i].begin(), arrays[i].end());
            maxV = *max_element(arrays[i].begin(), arrays[i].end());
            result = max(result, maxVal-minV);
            result = max(result, maxV-minVal);
            maxVal = max(maxVal, maxV);
            minVal = min(minVal, minV);
        }
        return result;
    }
};
