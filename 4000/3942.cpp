// 3942. Minimum Operations to Sort a Permutation
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0;

        int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool asc = true, dsc = true;

        for (int i=1; i<n; i++) {
            int x = nums[(start+i)%n];
            if (x!=i) asc = false;
            if (x!=n-i) dsc = false;
            if (!asc && !dsc) return -1;
        }

        if (asc) return min(start, n-start+2);
        return min(n-start, start+2);
    }
};
