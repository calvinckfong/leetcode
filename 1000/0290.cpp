// 290. Word Pattern
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string map[26]; // pattern[i] -> token
        unordered_set<char> p_set;
        unordered_set<string> t_set;
        stringstream ss(s);
        string token;
        int i=0, n=pattern.length();
        while (ss>>token)
        {
            // pattern is too short
            if (i>n-1) return false;

            if (map[pattern[i]-'a'] == "")
            {
                map[pattern[i]-'a'] = token;
                p_set.insert(pattern[i]);
                t_set.insert(token);
            }
            else if (token != map[pattern[i]-'a'])
                return false;
            i++;
        }
        // too few tokens in s
        if (i<n) return false;

        // Not 1-to-1 mapping
        if (p_set.size() != t_set.size())
            return false;

        return true;
    }
};
