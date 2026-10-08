// 1021. Remove Outermost Parentheses
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int d = 0;
        for (auto c: s) {
            if (c==')') d--;
            if (d)      res.push_back(c);
            if (c=='(') d++;
        }
        return res;
    }
};
