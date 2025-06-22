// 2138. Divide a String Into Groups of Size k
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for (int i=0; i<s.size(); i+=k) {
            string ss = s.substr(i, k);
            while (ss.size()<k)
                ss.push_back(fill);
            result.push_back(ss);
        }
        return result;
    }
};
