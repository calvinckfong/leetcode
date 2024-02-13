// 2980. Check if Bitwise OR Has Trailing Zeros
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]%2==0) cnt++;
            if (cnt>1) return true;
        }
        return false; 
    }
};
