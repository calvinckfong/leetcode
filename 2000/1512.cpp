// 1512. Number of Good Pairs
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0, n = nums.size();
        for (int j=0; j<n; j++)
        {
            for (int i=0; i<j; i++)
                if (nums[i]==nums[j]) result++;
        }
        return result;
    }
};
