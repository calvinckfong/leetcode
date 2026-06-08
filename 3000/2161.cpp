// 2161. Partition Array According to Given Pivot
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;

        for (auto n: nums) {
            if (n<pivot) res.push_back(n);
        }

        for (auto n: nums) {
            if (n==pivot) res.push_back(n);
        }

        for (auto n: nums) {
            if (n>pivot) res.push_back(n);
        }

        return res;
    }
};
