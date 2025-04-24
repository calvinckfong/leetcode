// 2799. Count Complete Subarrays in an Array
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinct(nums.begin(), nums.end());
        int dist_count = distinct.size();

        int result = 0;
        unordered_map<int, int> freq;
        for (int l=0, r=0; l<n; l++) {
            if (l>0) {
                int last = nums[l-1];
                freq[last]--;
                if (freq[last]==0) {
                    freq.erase(last);
                }
            }
            while (r<n && freq.size()<dist_count) {
                freq[nums[r]]++;
                r++;
            }
            if (freq.size() == dist_count) {
                result += (n-r+1);
            }
        }
        return result;
    }
};
