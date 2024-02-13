// 3034. Number of Subarrays That Match a Pattern I
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int cnt = 0;
        for (int i=0; i<nums.size()-pattern.size(); i++)
        {
            bool found = true;
            for (int k=0; k<pattern.size(); k++)
            {
                if (nums[i+k+1]>nums[i+k])
                    if (pattern[k]!=1) {found=false; break;}
                if (nums[i+k+1]<nums[i+k]) 
                    if (pattern[k]!=-1) {found=false; break;}
                if (nums[i+k+1]==nums[i+k])
                    if (pattern[k]!=0) {found=false; break;}
            }
            if (found) {
                // printf("%d\n", i);
                cnt++;
            }
        }
        return cnt;
    }
};
