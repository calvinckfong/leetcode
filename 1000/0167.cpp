// 167. Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, h=numbers.size()-1;
        while (h>l)
        {
            int sum = numbers[l]+numbers[h];
            if (sum>target)
                h--;
            else if (sum<target)
                l++;
            else
                return {l+1, h+1};
        }
        return {};
    }
};
