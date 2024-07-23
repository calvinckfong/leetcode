// 1636. Sort Array by Increasing Frequency
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        for (int i=0; i<nums.size(); i++)
            freq[nums[i]]++;

        vector<pair<int, int>> tmp(freq.begin(), freq.end());
        sort(tmp.begin(), tmp.end(), [=](pair<int, int>&a , pair<int, int>&b){
            if (a.second==b.second) return (a.first>b.first);
            return a.second<b.second;
        });

        int k=0;
        for (auto it: tmp) {
            for (int i=0; i<it.second; i++)
                nums[k++] = it.first;
        }
        return nums;
    }
};
