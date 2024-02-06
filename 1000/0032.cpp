// 32. Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pos({-1}); // positions of open bracket
        int maxlen = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '(')
            {
                // keep open bracket found
                pos.push(i);
            }
            else
            {
                // a valid parentheses is found.
                if (!pos.empty()) pos.pop();

                if (!pos.empty())
                    // keep the max length
                    maxlen = max(maxlen, i-pos.top());
                else
                    // no more elements in stack, keep current position in stack
                    pos.push(i);
            }
        }
        return maxlen;
    }
};
