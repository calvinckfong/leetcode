// 1356. Sort Integers by The Number of 1 Bits
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }

    static bool compare(int a, int b) {
        int a1 = __builtin_popcount(a);
        int b1 = __builtin_popcount(b);
        if (a1 == b1) return a < b;
        return a1<b1;
    }
};
