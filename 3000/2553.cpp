// 2553. Separate the Digits in an Array
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for (auto& x: nums) {
            vector<int> tmp;
            do {
                tmp.push_back(x%10);
                x/=10;
            } while (x>0);

            for (auto x=tmp.rbegin(); x!=tmp.rend(); ++x) {
                res.push_back(*x);
            }
        }

        return res;
    }
};
