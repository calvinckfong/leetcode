// 2542. Maximum Subsequence Score
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        int n=nums1.size();
        for (int i=0; i<n; i++)
            pairs.push_back({nums2[i], nums1[i]});

        // sort according to nums2 value
        sort(pairs.begin(), pairs.end());

        // for (int i=0; i<pairs.size(); i++)
        //     printf("%d %d\n", pairs[i].first, pairs[i].second);
        // printf("====\n");

        // setup priority queue to find sum of nums1
        long long ret=0, sum=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=n-1; i>=0; i--)
        {
            pq.push(pairs[i].second);
            sum += pairs[i].second;
            if (pq.size()>k)    // keep at-most k terms
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size()==k)
            {
                // printf("%d %d\n", pairs[i].first, sum);
                ret = max(ret, sum*pairs[i].first);
            }
        }

        return ret;
    }
};
