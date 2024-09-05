// 2028. Find Missing Observations
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int diff = mean*(m+n) - sum;
        if (diff > 6*n || diff<n) return {};

        vector<int> result(n);
        for (int i=0; i<n; i++) {
            result[i] = diff/(n-i);
            diff -= result[i];
        }
        return result;
    }
};
