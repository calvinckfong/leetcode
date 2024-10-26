// 2932. Maximum Strong Pair XOR I
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxVal = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<n-1; i++) {
            int x = nums[i];
            for (int j=i+1; j<n; j++) {
                int y = nums[j];
                if (abs(x-y) <= min(x, y))
                    maxVal = max(maxVal, x^y);
                else 
                    break;
            }
        }
        return maxVal;
    }
};
