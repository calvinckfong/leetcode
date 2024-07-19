// 1380. Lucky Numbers in a Matrix
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> result;

        vector<int> maxVal(n, 0);
        for (int i=0; i<m; i++) {
            vector<int>::iterator it = min_element(matrix[i].begin(), matrix[i].end());
            int idx = it - matrix[i].begin();
            if (maxVal[idx] == *it) {
                result.push_back(*it);
            }
            else if (maxVal[idx]==0) {
                int maxValue = 0;
                for (int j=0; j<m; j++)
                    maxValue = max(maxValue, matrix[j][idx]);
                maxVal[idx] = maxValue;
                if (maxValue == *it)
                    result.push_back(maxValue);
            }
        }
        return result;
    }
};
