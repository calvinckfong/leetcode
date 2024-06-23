// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQ, minQ;
        int l=0, n=nums.size(), maxLen=0;

        for (int r=0; r<n; r++) {
            while (!maxQ.empty() && maxQ.back()<nums[r]) {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[r]);
            while (!minQ.empty() && minQ.back()>nums[r]) {
                minQ.pop_back();
            }
            minQ.push_back(nums[r]);

            while (maxQ.front() - minQ.front() > limit) {
                if (nums[l] == maxQ.front())
                    maxQ.pop_front();
                if (nums[l] == minQ.front())
                    minQ.pop_front();
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
