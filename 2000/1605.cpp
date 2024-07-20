// 1605. Find Valid Matrix Given Row and Column Sums
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(), m=colSum.size();
        vector<vector<int>> result(n, vector<int>(m, 0));

        int i=0, j=0;
        while (i<n && j<m) {
            result[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= result[i][j];
            colSum[j] -= result[i][j];

            (rowSum[i]==0) ? i++ : j++;
        }
        return result;
    }
};
