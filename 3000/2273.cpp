// 2273. Find Resultant Array After Removing Anagrams
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res = {words[0]};
        int n = words.size();
        for (int i=1; i<n; i++) {
            if (compare(words[i], words[i-1])) {
                continue;
            }
            res.push_back(words[i]);
        }
        return res;
    }

private:
    bool compare(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        int freq[26] = {0};
        for (char c: s1) {
            ++freq[c-'a'];
        }
        for (char c: s2) {
            --freq[c-'a'];
        }
        for (int i=0; i<26; i++) {
            if (freq[i] != 0) return false;
        }
        return true;
    }
};
