// 1437. Check If All 1's Are at Least Length K Places
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt0 = 0, first = 1;
        for (int n: nums) {
            if (n == 1) {
                if (!first && cnt0 < k) return false;
                cnt0 = 0;
                first = 0;
            } else {
                cnt0++;
            }
        }

        return true;
    }
};
