// 2461. Maximum Sum of Distinct Subarrays With Length K
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0;
        int n=nums.size();
        unordered_map<int, int> freq;
        set<int> duplicates;

        long long sum = 0;
        for (int j=0; j<k; j++) {
            int curr = nums[j];
            freq[curr]++;
            sum+=curr;
            if (freq[curr]>1) duplicates.insert(curr);
        }
        if (duplicates.empty()) result = max(result, sum);

        for (int i=k; i<n; i++) {
            int tail = nums[i-k];
            int head = nums[i];
            freq[tail]--;
            freq[head]++;
            sum += head - tail;

            if (freq[tail]<2) duplicates.erase(tail);
            if (freq[head]>1) duplicates.insert(head);
            if (duplicates.empty()) result = max(result, sum);
        }
        return result;
    }
};
