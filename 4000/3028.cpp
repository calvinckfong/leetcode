// 3028. Ant on the Boundary
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt=0, pos=0;
        for (int i=0; i<nums.size(); i++)
        {
            pos += nums[i];
            if (pos==0) cnt++;
        }
        return cnt;
    }
};
