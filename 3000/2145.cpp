// 2145. Count the Hidden Sequences
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minVal = 0, maxVal = 0, cur = 0;
        int diff = upper - lower;
        for (int& d : differences) {
            cur += d;
            minVal = min(minVal, cur);
            maxVal = max(maxVal, cur);
            if (maxVal - minVal > diff) {
                return 0;
            }
        }
        return diff - (maxVal - minVal) + 1;
    }
};
