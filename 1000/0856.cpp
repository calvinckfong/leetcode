// 856. Score of Parentheses
class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, depth = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') {
                depth++;
            } else {
                depth--;
                if (s[i-1]=='(') res += (1<<depth);
            }
        }
        return res;
    }
};
