// 3033. Modify the Matrix
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxVal;

        for (int i=0; i<n; i++)
        {
            // find the max value in a column
            maxVal = -1;
            for (int j=0; j<m; j++)
                maxVal = max(maxVal, matrix[j][i]);
            
            // replace element value to max value 
            for (int j=0; j<m; j++)
                if (matrix[j][i]==-1) matrix[j][i]=maxVal;
        }
        return matrix;
    }
};
