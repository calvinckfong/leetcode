// 330. Patching Array
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result=0, i=0;
        long candidate=1;
        while (candidate<=n) {
            if (i<nums.size() && nums[i]<=candidate)
                candidate += nums[i++];
            else {
                candidate *= 2;
                result++;
            }
        }
        return result;
    }
};
