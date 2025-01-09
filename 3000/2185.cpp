// 2185. Counting Words With a Given Prefix
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0, n = pref.size();
        for (auto& w: words) {
            result += (w.substr(0,n) == pref);
        }
        return result;
    }
};
