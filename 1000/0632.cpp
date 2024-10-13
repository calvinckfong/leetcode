// 632. Smallest Range Covering Elements from K Lists
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> merged;
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums[i].size(); j++) {
                merged.push_back({nums[i][j], i});
            }
        }
        sort(merged.begin(), merged.end());

        int count = 0, l=0;
        int rangeMin = -1e5, rangeMax = 1e5;
        unordered_map<int, int> freq;
        for (int r=0; r<merged.size(); r++) {
            freq[merged[r].second]++;
            if (freq[merged[r].second]==1) count++;

            while (count == nums.size()) {
                int range = merged[r].first - merged[l].first;
                if (range < rangeMax - rangeMin) {
                    rangeMin = merged[l].first;
                    rangeMax = merged[r].first;
                }

                freq[merged[l].second]--;
                if (freq[merged[l].second]==0) count--;
                l++;
            }
        }
        return {rangeMin, rangeMax};
    }
};
