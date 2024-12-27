// 1014. Best Sightseeing Pair
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = INT_MIN, maxLeftScore=values[0], curr;
        int n = values.size();
        for (int i=1; i<n; i++) {
            curr = values[i] - i;
            result = max(result, maxLeftScore + curr);
            maxLeftScore = max(maxLeftScore, values[i]+i);
        }
        return result;
    }
};
