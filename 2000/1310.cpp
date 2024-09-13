// 1310. XOR Queries of a Subarray
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = arr.size();
        vector<int> result(n, 0);
        vector<int> tmp(m+1, 0);

        // compute arr[0] ^ ... ^ arr[i]
        for (int i=1; i<=m; i++) {
            tmp[i] = tmp[i-1] ^ arr[i-1];
        }

        for (int i=0; i<n; i++) {
            result[i] = tmp[queries[i][1]+1] ^ tmp[queries[i][0]];
        }
        return result;
    }
};
