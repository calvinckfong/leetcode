// 525. Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), result=0, sum=0;
        vector<int> len(2*n+1, INT_MIN);
        len[n] = -1;
        for (int i=0; i<nums.size(); i++)
        {
            sum += (nums[i])?1:-1;
            if (len[sum+n]>=-1)
                result = max(result, i-len[sum+n]);
            else 
                len[sum+n] = i;
        }
        return result;
    }
};
