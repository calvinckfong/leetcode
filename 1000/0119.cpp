// 119. Pascal's Triangle II
class Solution {
public:
    // Using the property that the n-th row r-th element is nCr
    // so the relationship between the (r-1)-th and the r-th element is
    // val = prevVal * (n-r+1) / r
    // nC0 and nCn are both equal to 1.
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        long long prevVal = 1, val;
        for (int i=1; i<rowIndex/2+1; i++)
        {
            val = prevVal * (rowIndex-i+1) / i;
            result[i] = result[rowIndex-i] = val;
            prevVal = val;
        }
        return result;
    }
};
