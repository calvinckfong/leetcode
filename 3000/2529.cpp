// 2529. Maximum Count of Positive Integer and Negative Integer
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count[2] = {0};
        for (int n: nums) {
            if (n>0) count[1]++;
            else if (n<0) count[0]++;
        }
        return max(count[0], count[1]);
    }
};
