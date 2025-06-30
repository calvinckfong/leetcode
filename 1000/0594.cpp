// 594. Longest Harmonious Subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i: nums) mp[i]++;

        int res = 0;
        for (auto& i: mp) {
            if (mp.count(i.first-1)>0)
                res = max(res, i.second + mp[i.first-1]);
        }

        return res;
    }
};
