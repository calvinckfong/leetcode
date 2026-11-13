// 3420. Count Non-Decreasing Subarrays After K Operations
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0, ops = 0;
        stack<int> st;
        vector<int> pos(n, n);
        vector<vector<int>> cnt(n);
        priority_queue<pair<int, int>> q;

        for (int l=0, r=0; r<n; r++) {
            while (!st.empty() && nums[r]>=nums[st.top()]) {
                pos[st.top()] = r;
                st.pop();
            }

            if (!st.empty()) {
                cnt[st.top()].push_back(r);
            }
            st.push(r);

            q.emplace(nums[r], r);
            ops += max(0, q.top().first - nums[r]);

            while (ops > k) {
                for (int i: cnt[l]) {
                    ops -= 1LL * (nums[l]-nums[i]) * (min(pos[i], r+1) - i);
                }
                l++;
            }

            while (!q.empty() && q.top().second < l) {
                q.pop();
            }

            res += r - l + 1;
        }
        return res;
    }
};
