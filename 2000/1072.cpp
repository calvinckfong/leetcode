// 1072. Flip Columns For Maximum Number of Equal Rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freq;

        int nCol = matrix[0].size();
        for (vector<int>& row: matrix) {
            string pattern = "";

            for (int col=1; col<nCol; col++) {
                pattern += (row[0] == row[col])?"T":"F";
            }
            freq[pattern]++;
        }

        int maxFreq = 0;
        for (auto& [k,v]: freq) {
            maxFreq = max(maxFreq, v);
        }
        return maxFreq;
    }
};
