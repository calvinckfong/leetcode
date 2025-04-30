// 1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto& n: nums) {
            while (n>=100) {
                n /= 100;
            }
            result += (n>=10);
        }
        return result;
    }
};
