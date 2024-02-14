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
            /*
            if (i%2) // odd location, -ve
            {
                while (nums[++last_neg]>0) ;
                result[i] = nums[last_neg];
            }
            else    // even location, +ve
            {
                while (nums[++last_pos]<0) ;
                result[i] = nums[last_pos];                
            }
            */
        }
        return result;
    }
};
