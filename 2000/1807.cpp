// 1807. Evaluate the Bracket Pairs of a String
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& x: knowledge) {
            dict[x[0]] = x[1];
        }

        bool keyFound = false;
        string res, key;
        for (char c: s) {
            if (c == '(') {
                keyFound = true;
            } else if (c == ')') {
                if (dict.count(key)>0) {
                    res += dict[key];
                } else {
                    res.push_back('?');
                }
                keyFound = false;
                key.clear();
            } else if (keyFound) {
                key.push_back(c);
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
