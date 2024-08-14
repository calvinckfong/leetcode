// 719. Find K-th Smallest Pair Distance
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n-1] - nums[0];
        int mid, count;
        while (low<high) {
            mid = low + (high-low)/2;

            count = countPairs(nums, mid);

            if (count<k) low = mid+1;
            else high = mid;
        }
        return low;
    }

private:
    int countPairs(vector<int>& nums, int maxDist) {
        int result = 0;
        int n = nums.size();

        for (int l=0, r=0; r<n; r++) {
            while (nums[r]-nums[l]>maxDist) {
                l++;
            }
            result += r-l;
        }
        return result;
    }
};
