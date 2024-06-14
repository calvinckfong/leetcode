// 945. Minimum Increment to Make Array Unique
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> freq(maxVal - minVal + n + 1);

        for (int i=0; i<nums.size(); i++) {
            freq[nums[i]-minVal]++;
        }

        int result = 0;
        for (int i=0; i<freq.size(); i++) {
            if (freq[i]>1) {
                freq[i+1] += freq[i]-1;
                result += freq[i]-1;
            }
        }
        return result;
    }
};
