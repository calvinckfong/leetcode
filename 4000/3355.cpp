// 3355. Zero Array Transformation I
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n+1, 0);
        for (const auto& q: queries) {
            delta[q[0]]++;
            delta[q[1]+1]--;
        }

        vector<int> freq;
        int i = 0;
        for (int& d: delta) {
            i += d;
            freq.push_back(i);
        }
        for (int i=0; i<n; i++) {
            if (freq[i]<nums[i]) return false;
        }
        return true;
    }
};
