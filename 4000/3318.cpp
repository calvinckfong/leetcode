// 3318. Find X-Sum of All K-Long Subarrays I
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        for (int i=0; i<=n-k; i++) {
            unordered_map<int, int> cnt;
            for (int j=i; j<i+k; j++)
                cnt[nums[j]]++;
            
            vector<pair<int, int>> freq;
            for (auto& [k, v]: cnt) {
                freq.emplace_back(v, k);
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            int xsum = 0;
            for (int j=0; j<x && j<freq.size(); j++) {
                xsum += freq[j].first * freq[j].second;
            }
            res.push_back(xsum);
        }

        return res;
    }
};
