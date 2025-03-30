// 763. Partition Labels
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0}, n = s.size();
        for (int i=0; i<n; i++) {
            last[s[i]-'a'] = i;
        }

        int l=0, r=0;
        vector<int> result;
        for (int i=0;i<n; i++) {
            r = max(r, last[s[i]-'a']);
            if (r == i) {
                result.push_back(i-l+1);
                l = i+1;
            }
        }
        return result;
    }
};
