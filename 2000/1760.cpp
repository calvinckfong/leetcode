// 1760. Minimum Limit of Balls in a Bag
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // binary search
        int l=1, r=*max_element(nums.begin(), nums.end());

        while (l<r) {
            int m = l + (r-l)/2, total=0;

            for (int n: nums) {
                total += ((n-1) / m);
            }

            if (total <= maxOperations) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};
