// 14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), [](string a, string b){
            return a.size()<b.size();
        });
        string ret = strs[0]; // shortest string
        
        for (int i=0; i<n; i++)
        {
            while (ret.size()>0 && strs[i].find(ret)!=0)
            {
                ret.pop_back();
            }
        }
        return ret;
    }
};
