// 2099. Find Subsequence of Length K With the Largest Sum
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> p(n);
        for (int i=0; i<n; i++) {
            p[i] = {nums[i], i};
        }
        sort(p.begin(), p.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });
        sort(p.begin(), p.begin()+k, [](auto& a, auto& b){
            return a.second < b.second;
        });
        vector<int> res(k);
        for (int i=0; i<k; i++)
            res[i] = p[i].first;
        return res;
    }
};
