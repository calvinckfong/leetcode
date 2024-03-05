// 1750. Minimum Length of String After Deleting Similar Ends
class Solution {
public:
    int minimumLength(string s) {
        int l=0, r=s.size()-1;

        while (r>l)
        {
            if (s[l]!=s[r]) break;

            do {l++;} while (s[l]==s[l-1] && l<r);
            do {r--;} while (s[r]==s[r+1] && l<r);
        }
        return r-l+1;
    }
};
