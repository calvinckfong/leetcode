// 3718. Smallest Missing Multiple of K
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int res = 0;
        bool found = true;
        do {
            res += k;
            found = find(nums.begin(), nums.end(), res) != nums.end();
        } while (found);
        return res;
    }
};
