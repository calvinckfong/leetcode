// 1390. Four Divisors
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (auto& x: nums) {
            unordered_set<int> s;
            int i = 1, j = x;
            do {
                if (x % i == 0) {
                    s.insert(i);
                    s.insert(j);
                }
                i++;
                j=x/i;
            } while (i<=j);
            if (s.size()==4) {
                for (auto& x: s) {
                    res += x;
                }
            }
        }
        return res;
    }
};
