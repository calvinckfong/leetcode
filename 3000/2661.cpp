// 2661. First Completely Painted Row or Column
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> num2Pos(m*n);

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                num2Pos[mat[i][j]-1] = {i, j};

        vector<int> rowCnt(m), colCnt(n);
        for (int i=0; i<m*n; i++) {
            int num = arr[i];
            auto& [r, c] = num2Pos[num-1];

            rowCnt[r]++;
            colCnt[c]++;

            if (rowCnt[r]==n || colCnt[c]==m) return i;
        }

        return -1;
    }
};
