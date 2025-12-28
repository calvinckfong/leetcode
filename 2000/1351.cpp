// 1351. Count Negative Numbers in a Sorted Matrix
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (auto& v: grid) {
            for (auto e: v) {
                res += (e<0);
            }
        }
        return res;
    }
};
