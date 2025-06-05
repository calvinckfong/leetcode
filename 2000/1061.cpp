// 1061. Lexicographically Smallest Equivalent String
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        
        char c[26];
        for (int i=0; i<26; i++) {
            c[i] = 'a' + i;
        }

        for (int i=0; i<n; i++) {
            char src = max(c[s1[i]-'a'], c[s2[i]-'a']);
            char tar = min(c[s1[i]-'a'], c[s2[i]-'a']);
            for (int j=0; j<26; j++) {
                if (c[j] == src) c[j] = tar;
            }
        }

        for (int i=0; i<baseStr.size(); i++)
            baseStr[i] = c[baseStr[i]-'a'];

        return baseStr;
    }
};
