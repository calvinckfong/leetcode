// 862. Shortest Subarray with Sum at Least K
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sums(n+1, 0LL);
        for (int i=0; i<n; i++)
            sums[i+1] = sums[i] + nums[i];

        int result = INT_MAX;
        deque<int> subarray;
        for (int i=0; i<=n; i++) {
            // shrink to minimum length that sum > k
            while (!subarray.empty() && sums[i]-sums[subarray.front()] >= k) {
                result = min(result, i-subarray.front());
                subarray.pop_front();
            }

            // remove large sum at the back
            while (!subarray.empty() && sums[i]<=sums[subarray.back()]) {
                subarray.pop_back();
            }

            // queue next
            subarray.push_back(i);
        }
        
        return (result==INT_MAX)?-1:result;
    }
};
