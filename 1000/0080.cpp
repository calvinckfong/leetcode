// 80. Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> tmp;
        int cnt = 0, last = -1e5;
        auto it = nums.begin();
        while (it!=nums.end())
        {
            if (*it != last)
            {
                last = *it;
                cnt = 1;
                ++it;
            }
            else if (cnt < 2)
            {
                cnt++;
                ++it;
            }
            else
            {
                nums.erase(it);
            }
        }

        return nums.size();
    }
};
