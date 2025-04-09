// 3375. Minimum Operations to Make Array Values Equal to K
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (auto& n: nums) {
            if (n < k)  return -1;
            else if (n>k) s.insert(n);
        }
        return s.size();
    }
};
