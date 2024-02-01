// 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        for (auto it=nums.begin(); it!=nums.end(); ++it)
        {
            if (val != *it)
                res.push_back(*it);
        }
        nums = res;
        return nums.size();
    }
};
