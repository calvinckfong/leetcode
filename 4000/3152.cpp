// 3152. Special Array II
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int nq = queries.size();
        vector<int> prefix(n, 0);
        int curr, last = nums[0]&1;
        for (int i=1; i<n; i++) {
            curr = nums[i]&1;
            prefix[i] = prefix[i-1] + (last==curr);
            last = curr;
        }

        vector<bool> result(nq);
        for (int i=0; i<nq; i++) {
            vector<int> q = queries[i];
            result[i] = (prefix[q[1]] == prefix[q[0]]);
        }
        
        return result;
    }
};
