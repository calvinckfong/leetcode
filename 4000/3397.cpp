// 3397. Maximum Number of Distinct Elements After Operations
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=0, prev=INT_MIN;
        for (int x: nums) {
            int curr = min(max(x-k, prev+1), x+k);
            if (curr>prev) {
                res++;
                prev = curr;
            }
        }
        return res;
    }
};
