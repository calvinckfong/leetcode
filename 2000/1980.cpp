// 1980. Find Unique Binary String
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i=0; i<nums.size(); i++) {
            char c = nums[i][i];
            result += '0' + (c == '0');
        }
        return result;
    }
};
