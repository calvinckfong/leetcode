// 1190. Reverse Substrings Between Each Pair of Parentheses
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int> opens;
        string result;

        for (int i=0; i<n; i++) {
            if (s[i]=='(')
                opens.push_back(result.size());
            else if (s[i]==')') {
                reverse(result.begin()+opens.back(), result.end());
                opens.pop_back();
            }
            else 
                result += s[i];
        }
        return result;
    }
};
