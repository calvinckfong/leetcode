// 73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> rows, cols;

        // store all position with zero
        vector<vector<int>> zeros;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }

        // set rows
        for (auto it: rows)
            matrix[it] = vector<int>(n, 0);

        // set cols
        for (auto it: cols)
            for (int i=0; i<m; i++)
                matrix[i][it] = 0;
    }
};
