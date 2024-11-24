// 1975. Maximum Matrix Sum
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cntZero = 0, cntNeg = 0, minAbs = INT_MAX;

        long long result = 0;
        for (vector<int>& vec: matrix) {
            for (int& val: vec) {
                result += abs(val);
                if (val==0) {
                    cntZero++;
                } else {
                    minAbs = min(minAbs, abs(val));
                    if (val<0) cntNeg++;
                }
            }
        }
        return result + ((cntNeg%2 && cntZero==0)?-2*minAbs:0);
    }
};
