// 2579. Count Total Number of Colored Cells
class Solution {
public:
    long long coloredCells(int n) {
        long long result = (long long)(n-1)*(long long)(n)/2;
        return result * 4 + 1;
    }
};
