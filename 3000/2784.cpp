// 2784. Check if Array is Good
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int cnt[201] = {0};

        for (int& x: nums) {
            if (x >= n) return false;

            if (x<n-1 && cnt[x]>0)  return false;

            if (x==n-1 && cnt[x]>1) return false;

            cnt[x]++;
        }

        return true;
    }
};
