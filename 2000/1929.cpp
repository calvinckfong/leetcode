// 1929. Concatenation of Array
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(2*n);

        for (int i=0; i<n; i++)
            result[n+i] = result[i] = nums[i];
        
        return result;
    }
};
