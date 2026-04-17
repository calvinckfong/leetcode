// 3761. Minimum Absolute Distance Between Mirror Pairs
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prev;
        int res = 2e5;
        for (int i=0; i<n; i++) {
            int x = nums[i];
            if (prev.count(x)) {
                res = min(res, i-prev[x]);
            }
            prev[reverse(x)] = i;
        }
        return (res==2e5)?-1:res;
    }

private:
    int reverse(int x) {
        int res = 0;
        while (x>0) {
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
};
