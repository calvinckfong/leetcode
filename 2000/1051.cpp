// 1051. Height Checker
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size(), result=0;
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        for (int i=0; i<n; i++) {
            result += (heights[i] != expected[i]);
        }
        return result;
    }
};
