// 1733. Minimum Number of People to Teach
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> cncon;
        for (auto& f: friendships) {
            unordered_map<int, int> mp;
            bool comm = false;
            for (int lang: languages[f[0]-1]) {
                mp[lang] = 1;
            }
            for (int lang: languages[f[1]-1]) {
                if (mp[lang]) {
                    comm = true;
                    break;
                }
            }
            if (!comm) {
                cncon.insert(f[0]-1);
                cncon.insert(f[1]-1);
            }
        }

        int max_cnt = 0;
        vector<int> cnt(n+1, 0);
        for (auto& f: cncon) {
            for (int lang: languages[f]) {
                cnt[lang]++;
                max_cnt = max(max_cnt, cnt[lang]);
            }
        }
        return cncon.size() - max_cnt;
    }
};
