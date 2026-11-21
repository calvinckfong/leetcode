// 3331. Find Subtree Sizes After Changes
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> first(n, -1);
        vector<int> next(n, -1);
        for (int i=n-1; i>0; i--) {
            next[i] = first[parent[i]];
            first[parent[i]] = i;
        }

        vector<int> size(n, 1), above(n);
        int last[26] = {0};
        for (int i=0; i<26; i++) last[i] = -1;

        vector<int> st = {0};
        while (!st.empty()) {
            int x = st.back();
            st.pop_back();

            if (x>=0) {
                int i = s[x] - 'a';
                above[x] = last[i];
                last[i] = x;
                st.push_back(~x);
                for (int child = first[x]; child!=-1; child=next[child]) {
                    st.push_back(child);
                }
            } else {
                x = ~x;
                last[s[x]-'a'] = above[x];
                if (x) {
                    size[above[x]>=0?above[x]:parent[x]] += size[x]; 
                }
            }
        }
        return size;
    }
};
