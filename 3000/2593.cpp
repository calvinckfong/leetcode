// 2593. Find Score of an Array After Marking All Elements
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);

        vector<pair<int, int>> sorted(n);
        for (int i=0; i<n; i++)
            sorted[i] = make_pair(nums[i], i);
        sort(sorted.begin(), sorted.end());
        
        long long result = 0;
        for (int i=0; i<n; i++) {
            auto p = sorted[i];
            int num = p.first;
            int idx = p.second;

            if (!marked[idx]) {
                result += num;
                marked[idx] = true;

                if (idx>0)      marked[idx-1] = true;
                if (idx<n-1)    marked[idx+1] = true;
            }
        }
        return result;
    }
};
