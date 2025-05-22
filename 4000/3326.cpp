// 3362. Zero Array Transformation III
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });

        int n = nums.size(), nq = queries.size();
        priority_queue<int> pq;
        vector<int> delta(n+1, 0);
        int operations = 0;
        for (int i=0, j=0; i<n; i++) {
            operations += delta[i];
            while (j<nq && queries[j][0]==i) {
                pq.push(queries[j][1]);
                j++;
            }

            while (operations<nums[i] && !pq.empty() && pq.top()>=i) {
                operations++;
                delta[pq.top()+1]--;
                pq.pop();
            }

            if (operations<nums[i]) return -1;
        }
        return pq.size();
    }
};
