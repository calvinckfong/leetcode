// 3514. Number of Unique XOR Triplets II
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        int u = 1;
        while (u<=m) u<<=1;

        vector<int> s(u);
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                s[nums[i]^nums[j]] = 1;
            }
        }

        vector<int> t(u);
        for (int i=0; i<u; i++) {
            if (!s[i]) continue;
            for (int j: nums) {
                t[i^j] = 1;
            }
        }

        int res = 0;
        for (int i=0; i<u; i++) {
            res += t[i];
        }
        return res;
    }
};
