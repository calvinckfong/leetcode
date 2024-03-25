// 442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int freq[100001] = {0}, curr;
        vector<int> result;
        for (int i=0; i<nums.size(); i++)
        {
            curr = abs(nums[i]);
            freq[curr]++;
            if (freq[curr]>1) result.push_back(curr);
        }
        return result;
    }
};
