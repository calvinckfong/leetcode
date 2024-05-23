// 2597. The Number of Beautiful Subsets
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;

        return findSubsets(nums, k, freq, 0)-1;
    }

private:
    int findSubsets(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) return 1;

        int result = findSubsets(nums, k, freq, i+1);
        if (freq[nums[i] - k]==0) {
            freq[nums[i]]++;
            result += findSubsets(nums, k, freq, i+1);
            freq[nums[i]]--;
        }
        return result;
    }
};
