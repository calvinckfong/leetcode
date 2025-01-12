// 2116. Check if a Parentheses String Can Be Valid
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n%2) return false;
        int unlocked=0, open=0;
        for (int i=0; i<n; i++) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == '(') {
                open++;
            } else {
                if (open>0)
                    open--;
                else if (unlocked>0)
                    unlocked--;
                else {
                    return false;
                }
            }
        }

        int balance = 0;
        for (int i=n-1; i>=0; i--) {
            if (locked[i]=='0') {
                balance--;
                unlocked--;
            } else if (s[i] == '(') {
                balance++;
                open--;
            } else if (s[i] == ')') {
                balance--;
            }

            if (balance>0) return false;

            if (unlocked==0 && open==0) break;
        }

        if (open>0) return false;
        return true;
    }
};
