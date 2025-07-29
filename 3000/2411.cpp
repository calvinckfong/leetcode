// 2411. Smallest Subarrays With Maximum Bitwise OR
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos (31, -1);
        vector<int> res(n);

        for (int i=n-1; i>=0; i--) {
            int j=i;
            for (int b=0; b<31; b++) {
                if (!(nums[i] & (1<<b))) {
                    if (pos[b] != -1) {
                        j = max(j, pos[b]);
                    }
                } else {
                    pos[b] = i;
                }
            }
            res[i] = j-i+1;
        }
        return res;
    }
};
