// 2200. Find All K-Distant Indices in an Array
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size(), d = n;
        vector<int> dist(n, INT_MAX);
        for (int i=0; i<n; i++) {
            if (nums[i]==key) {
                d = 0;
            } else {
                d++;
            }
            dist[i] = min(dist[i], d);
        }
        d = n;
        for (int i=n-1; i>=0; i--) {
            if (nums[i]==key) {
                d = 0;
            } else {
                d++;
            }
            dist[i] = min(dist[i], d);
        }
        vector<int> res;
        for (int i=0; i<n; i++) {
            if (dist[i]<=k) res.push_back(i);
        }
        return res;

    }
};
