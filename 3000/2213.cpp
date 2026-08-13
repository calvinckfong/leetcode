// 2213. Longest Substring of One Repeating Character
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        set<pair<int, int>> segs;
        multiset<int> lens;

        for (int i=0; i<n;) {
            int j = i;
            while (j<n && s[j]==s[i]) j++;
            segs.insert({i, j-1});
            lens.insert(j-i);
            i = j;
        }

        int m = queryIndices.size();
        vector<int> res(m);

        for (int i=0; i<m; i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            if (s[pos] != c) {
                auto it = segs.upper_bound({pos, INT_MAX});
                it--;
                int L = it->first, R = it->second;
                segs.erase(it);
                lens.erase(lens.find(R-L+1));

                if (L<pos) {
                    segs.insert({L, pos-1});
                    lens.insert(pos-L);
                }

                if (R>pos) {
                    segs.insert({pos+1, R});
                    lens.insert(R-pos);
                }

                int nL = pos, nR = pos;
                auto rIt = segs.lower_bound({pos+1, 0});
                if (rIt!=segs.end() && rIt->first==pos+1 && s[pos+1]==c) {
                    lens.erase(lens.find(rIt->second - rIt->first + 1));
                    nR = rIt->second;
                    segs.erase(rIt);
                }

                auto lIt = segs.lower_bound({pos, 0});
                if (rIt!=segs.begin()) {
                    lIt--;
                    if (lIt->second==pos-1 && s[pos-1]==c) {
                        lens.erase(lens.find(lIt->second - lIt->first + 1));
                        nL = lIt->first;
                        segs.erase(lIt);
                    }
                }

                segs.insert({nL, nR});
                lens.insert(nR-nL+1);
                s[pos] = c;
            }

            res[i] = *lens.rbegin();
        }

        return res;
    }
};
