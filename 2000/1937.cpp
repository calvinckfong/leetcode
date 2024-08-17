// 1937. Maximum Number of Points with Cost
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(), n=points[0].size();
        vector<long long> currRow(n), prevRow(n);

        long long maxVal;
        for (int i=0; i<m; i++) {
            
            maxVal = 0;
            for (int j=0; j<n; j++) {
                maxVal = max(maxVal-1, prevRow[j]);
                currRow[j] = maxVal;
            }

            maxVal = 0;
            for (int j=n-1; j>=0; j--) {
                maxVal = max(maxVal-1, prevRow[j]);
                currRow[j] = max(currRow[j], maxVal) + points[i][j];
            } 

            prevRow = currRow;
        }

        return *max_element(prevRow.begin(), prevRow.end());
    }
};
