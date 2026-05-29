// 3300. Minimum Element After Replacement With Digit Sum
class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (auto& i: nums) {
            digitSum(i, res);
        }
        return res;
    }

private:
    void digitSum(int x, int& res) {
        int sum = 0;
        while (x) {
            sum += (x % 10);
            if (sum>res) return;
            x /= 10;
        }
        res = sum;
    }
};
