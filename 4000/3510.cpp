// 3510. Minimum Pair Removal to Sort Array II
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return 0;

        vector<long long> arr(nums.begin(), nums.end());
        vector<bool> removed(n, false);
        priority_queue<pair<long long, int>, 
            vector<pair<long long, int>>, 
            greater<>> pq;

        int sorted = 0;
        for (int i=1; i<n; i++) {
            pq.emplace(arr[i-1]+arr[i], i-1);
            if (arr[i]>=arr[i-1]) sorted++;
        }
        if (sorted == n-1) return 0;

        int rem = n;
        vector<int> prev(n), next(n);
        for (int i=0; i<n; i++) {
            prev[i] = i-1;
            next[i] = i+1;
        }

        while (rem>1) {
            auto [sum, l] = pq.top();
            pq.pop();
            int r = next[l];
            if (r>=n || removed[l] || removed[r] || arr[l]+arr[r]!=sum)
                continue;

            int pre = prev[l];
            int nxt = next[r];

            if (arr[l] <= arr[r])
                sorted--;
            if (pre!=-1 && arr[pre]<=arr[l])
                sorted--;
            if (nxt!=n && arr[nxt]>=arr[r])
                sorted--;

            arr[l] += arr[r];
            removed[r] = true;
            rem--;

            if (pre==-1) {
                prev[l] = -1;
            } else {
                pq.emplace(arr[pre]+arr[l], pre);
                if (arr[pre]<=arr[l]) sorted++;
            }

            if (nxt==n) {
                next[l] = n;
            } else {
                prev[nxt] = l;
                next[l] = nxt;
                pq.emplace(arr[l]+arr[nxt], l);
                if (arr[l]<=arr[nxt]) sorted++;
            }

            if (sorted == rem-1)
                return n-rem;
        }
        return n;
    }
};
