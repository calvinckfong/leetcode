// 977. Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        vector<int> result;
        while (i<j)
        {
            if (abs(nums[i]) > abs(nums[j])){
                result.push_back(nums[i]*nums[i]);
                i++;
            } else {
                result.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        result.push_back(nums[i]*nums[i]);
        reverse(result.begin(), result.end());
        return result;
    }
};
