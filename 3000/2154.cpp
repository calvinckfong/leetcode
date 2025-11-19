// 2154. Keep Multiplying Found Values by Two
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int res = original;
        auto it=nums.begin();
        while (it != nums.end()) {
            auto next = find(it, nums.end(), res);
            if (next != nums.end()) {
                res *= 2;
                it == next;
            } else
                break;
        }

        return res;
    }
};
