// 2161. Partition Array According to Given Pivot
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result, more, eq;

        for (auto& n: nums) {
            if (n<pivot)    
                result.push_back(n);
            else if (n>pivot)
                more.push_back(n);
            else
                eq.push_back(n);
        }
        for (auto& n: eq)   result.push_back(n);
        for (auto& n: more) result.push_back(n);

        return result;
    }
};
