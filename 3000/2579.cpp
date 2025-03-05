// 2579. Count Total Number of Colored Cells
class Solution {
public:
    long long coloredCells(int n) {
        long long result = 0;
        while (--n>0) {
            result += n;
        }
        return result * 4 + 1;
    }
};
