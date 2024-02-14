// 2149. Rearrange Array Elements by Sign
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int ppos=0, npos=1;
        vector<int> result(nums.size());
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]>0) {
                result[ppos] = nums[i];
                ppos+=2;
            } else {
                result[npos] = nums[i];
                npos+=2;
            }
        }
        return result;
    }
};
