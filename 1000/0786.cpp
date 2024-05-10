// 786. K-th Smallest Prime Fraction
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<double, vector<int>>> q;

        int n=arr.size();
        for (int i=0; i<n; i++) {
            q.push({ -1.0*arr[i]/arr.back(), {i, n-1} });
        }

        while (--k>0) {
            vector<int> curr = q.top().second;
            q.pop();
            curr[1]--;
            q.push({ -1.0*arr[curr[0]]/arr[curr[1]], 
                {curr[0], curr[1]} });
            
        }

        vector<int> res = q.top().second;
        return {arr[res[0]], arr[res[1]]};
    }
};
