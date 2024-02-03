// 205. Isomorphic Strings
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //unordered_map<char, char> lookup_s2t, lookup_t2s;
        char lookup_s2t[128], lookup_t2s[128];

        memset(lookup_s2t, -1, 128);
        memset(lookup_t2s, -1, 128);

        for (int i=0; i<s.size(); i++)
        {
            if (lookup_s2t[s[i]] != lookup_t2s[t[i]]) 
                // mismatch
                return false;
            else {
                // new key
                lookup_s2t[s[i]] = i;
                lookup_t2s[t[i]] = i;
            }
        }
        return true;
    }
};
