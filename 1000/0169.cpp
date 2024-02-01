// 169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int th = n/2;
        unordered_map<int, int> freq;
        for (auto it: nums)
        {
            freq[it]++;
            if (freq[it]>th) return it;
        }
        return 0;
    }
};
