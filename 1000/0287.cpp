// 287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int freq[100001] = {0}, curr;
        for (int i=0; i<nums.size(); i++) {
            curr = nums[i];
            if (freq[curr]>0) return curr;
            else freq[curr]++;
        }
        return -1;
    }
};
