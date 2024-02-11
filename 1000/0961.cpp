// 961. N-Repeated Element in Size 2N Array
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size()/2;
        for (int i=0; i<2*n; i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};
