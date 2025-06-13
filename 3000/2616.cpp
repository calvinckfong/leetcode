// 2616. Minimize the Maximum Difference of Pairs
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l=0, r = nums[n-1] - nums[0];
        while (l<r) {
            int m = (l+r)/2;

            if (countPairs(nums, m)>=p) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }

private:
    int countPairs(vector<int>& nums, int p) {
        int n = nums.size(), res=0;
        for (int i=0; i<n-1; i++) {
            if (nums[i+1]-nums[i] <= p) {
                res++;
                i++;
            }
        }
        return res;
    }
};
