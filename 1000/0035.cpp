// 35. Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n;
        
        if (target<=nums[0])    return 0;
        else if (target>nums[n-1]) return n;

        while (l<h)
        {
            int m = l + (h-l)/2;
            if (m==0 || m==n-1) return m;

            if (nums[m-1]<target && nums[m]>=target)
                return m;
            else if (nums[m-1]>=target)
                h = m;
            else
                l = m;
        }
        return h;
    }
};
