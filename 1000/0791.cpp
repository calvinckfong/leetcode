// 791. Custom Sort String
class Solution {
public:
    string customSortString(string order, string s) {
        // find the number of appearence of each characters in `s`
        int cnt[26] = {0};
        for (int i=0; i<s.size(); i++)
            cnt[s[i]-'a']++;
        
        // reorder according the `order`
        string result;
        for (int i=0; i<order.size(); i++)
        {
            for (int j=0; j<cnt[order[i]-'a']; j++)
                result += order[i];
            cnt[order[i]-'a'] = 0;
        }

        // append remainings not in `order`
        for (int i=0; i<26; i++)
            for (int j=0; j<cnt[i]; j++)
                result += ('a' + i);

        return result;
    }
};
