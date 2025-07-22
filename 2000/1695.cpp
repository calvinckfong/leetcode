// 1695. Maximum Erasure Value
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=0, sum=0, res=0, curr;
        vector<int> seen(10001, -1);

        while (r<n)
        {
            int curr = nums[r];
            if (seen[curr] != -1) {
                while (l<=seen[curr]) {
                    sum-=nums[l++];
                }
            }
            sum+=curr;
            res = max(res, sum);
            seen[curr] = r;
            r++; 
        }
        return res;
    }
};
