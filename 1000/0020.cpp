// 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push(s[i]);
            else if (s[i] == ')')
            {
                if (stack.empty()) return   false;
                if (stack.top() == '(')    stack.pop();
                else    return false;
            }
            else if (s[i] == ']')
            {
                if (stack.empty()) return   false;
                if (stack.top() == '[')    stack.pop();
                else    return false;
            }
            else if (s[i] == '}')
            {
                if (stack.empty()) return   false;
                if (stack.top() == '{')    stack.pop();
                else    return false;
            }
        }
        
        return stack.empty();
    }
};
