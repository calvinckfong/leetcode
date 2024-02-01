// 151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ret, tok;
        while (ss >> tok)
        {
            ret = tok + " " + ret;
        }
        return ret.substr(0, ret.size()-1);
    }
};
