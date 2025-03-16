// 2226. Maximum Candies Allocated to K Children
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxVal = accumulate(candies.begin(), candies.end(), 0LLU) / k;
        int n = candies.size();

        int l=0, r=maxVal;
        while (l<r) {
            int mid = l + (r-l+1)/2;

            long long maxChildren = 0;
            for (int i=0; i<n; i++) {
                maxChildren += candies[i] / mid;
            }

            if (maxChildren >= k)   l = mid;
            else                    r = mid-1; 
        }
        return l;
    }
};
