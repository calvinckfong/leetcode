// 995. Minimum Number of K Consecutive Bit Flips
class Solution {
public:
    const int StartOfFlip = 2;
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int currentFlips=0, totalFlips=0;

        for (int i=0; i<n; i++) {
            if (i>=k && nums[i-k]==StartOfFlip)
                currentFlips--;
            
            if ((currentFlips%2) == nums[i]) {
                // out of bound
                if (i+k>n) return -1;
                nums[i] = StartOfFlip;
                currentFlips++;
                totalFlips++;
            }
        }
        return totalFlips;
    }
};
