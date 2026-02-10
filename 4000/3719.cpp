// 3719. Longest Balanced Subarray I
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i=0; i<n; i++) {
            set<int> seen;
            int oddCnt=0, evenCnt=0;
            for (int j=i; j<n; j++) {
                int x = nums[j];
                if (seen.count(x)==0) {
                    seen.insert(x);
                    if (x&1) oddCnt++;
                    else evenCnt++;
                }
                if (oddCnt==evenCnt) res = max(res, j-i+1);
            }
            if (n-i <= res) return res;
        }
        return res;
    }
};
