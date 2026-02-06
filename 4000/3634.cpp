// 3634. Minimum Removals to Balance Array
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = n, r = 0;
        for (int l=0; l<n; l++) {
            while (r<n && nums[r]<= (1LL * k * nums[l]))
                r++;
            res = min(res, n-(r-l));
        }
        return res;
    }
};
