// 1249. Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int o=0;
        // first pass: mark unused ')' as '*'
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ')')
                if (o>0) o--;
                else s[i] = '*';
            else if (s[i] == '(')
                o++;
        }

        // second pass: mark unused '(' as '*'
        for (int i=s.size()-1; i>=0; i--) {
            if (o>0 && s[i]=='(') {
                s[i] = '*';
                o--;
            }
        }

        // final '*' from string
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
