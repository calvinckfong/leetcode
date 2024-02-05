// 3005. Count Elements With Maximum Frequency
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto it: nums)
            freq[it]++;

        int max_freq = 0;
        for (auto &it:freq)
            max_freq = max(it.second, max_freq);
        
        int ret = 0;
        for (auto &it:freq)
        {
            if (it.second == max_freq)
                ret++;
        }
        return ret*max_freq;
    }
};
