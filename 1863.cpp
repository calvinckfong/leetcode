// 1863. Sum of All Subset XOR Totals
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for (auto i: nums)
            result |= i;
            
        return result << (nums.size()-1);
    }
};
