// 1488. Avoid Flood in The City
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        set<int> st;
        unordered_map<int, int> mp;

        for (int i=0; i<n; ++i) {
            if (rains[i] > 0) {
                res[i] = -1;
                if (mp.count(rains[i])) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it==st.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    st.erase(it);
                }
                mp[rains[i]] = i;
            } else {
                st.insert(i);
            }
        }
        return res;
    }
};
