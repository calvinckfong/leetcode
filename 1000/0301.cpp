// 301. Remove Invalid Parentheses
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        forward(s, res, 0, 0);
        return res;
    }

private:
    void forward(string s, vector<string>& res, int si, int sj) {
        int bal = 0;

        for (int i=si; i<s.size(); i++) {
            bal += (s[i]=='(') - (s[i]==')');

            if (bal>=0) continue;

            for (int j=sj; j<=i; j++) {
                if (s[j]==')' && (j==sj || s[j-1]!=')'))
                    forward(s.substr(0, j) + s.substr(j+1), res, i, j);
            }
            return;
        }

        backward(s, res, s.size()-1, s.size()-1);
    }

    void backward(string s, vector<string>& res, int si, int sj) {
        int bal = 0;

        for (int i=si; i>=0; i--) {
            bal += (s[i]==')') - (s[i]=='(');

            if (bal>=0) continue;

            for (int j=sj; j>=i; j--) {
                if (s[j]=='(' && (j==sj || s[j+1]!='('))
                    backward(s.substr(0, j) + s.substr(j+1), res, i-1, j-1);
            }
            return;
        }

        res.push_back(s);
    }
};
