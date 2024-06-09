// 974. Subarray Sums Divisible by K
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), result=0;
        vector<int> rem(k, 0);
        rem[0] = 1;
        for (int i=0, idx=0; i<n; i++) {
            idx = (idx+nums[i]%k+k)%k; 
            result += rem[idx];
            rem[idx]++;
        }
        return result;
    }
};
