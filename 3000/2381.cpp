// 2381. Shifting Letters II
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> add(n+1);

        for (auto ss: shifts) {
            if (ss[2]) {
                add[ss[0]]++;
                add[ss[1]+1]--;
            } else {
                add[ss[0]]--;
                add[ss[1]+1]++;
            }
        }

        int change = 0;
        for (int i=0; i<n; i++) {
            change = (change + add[i]) % 26;
            s[i] = (((change + s[i] - 'a') + 26) % 26) + 'a';
        }
        return s;
    }
};
