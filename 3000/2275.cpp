// 2275. Largest Combination With Bitwise AND Greater Than Zero
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int result = 0;
        for (int i=0; i<24; i++) {
            int count = 0;
            for (int j=0; j<n; j++) {
                count += ((candidates[j]>>i)&1);
            }
            result = max(count, result);
        }
        return result;
    }
};
