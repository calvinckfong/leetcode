// 761. Special Binary String
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return s;
        vector<string> res;
        int cnt = 0;

        for (int i=0, j=0; i<s.size(); i++) {
            cnt += (s[i]=='1')?1:-1;
            if (cnt==0) {
                res.push_back("1" + makeLargestSpecial(s.substr(j+1, i-j-1)) + "0");
                j = i + 1;
            }
        }

        sort(res.begin(), res.end(), greater<string>());
        return accumulate(res.begin(), res.end(), ""s);
    }
};
