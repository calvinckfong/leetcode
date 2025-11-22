// 3190. Find Minimum Operations to Make All Elements Divisible by Three
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int& n: nums) {
            res += ((n % 3)!=0);
        }
        return res;
    }
};
