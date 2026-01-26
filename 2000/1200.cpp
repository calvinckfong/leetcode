// 1200. Minimum Absolute Difference
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), min_diff = INT_MAX;
        vector<vector<int>> res;

        for (int i=1; i<n; i++) {
            if (arr[i]-arr[i-1]<min_diff) {
                min_diff = arr[i] - arr[i-1];
                res.clear();
                res.push_back({arr[i-1], arr[i]});
            } else if (arr[i]-arr[i-1] == min_diff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};
