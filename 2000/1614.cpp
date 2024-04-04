// 1614. Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        if (s.size()==0) return 0;
        int depth=0, maxD=0;
        for (char c : s) {
            if (c == '(')
                maxD = max(maxD, ++depth);
            else if (c == ')')
                depth--; 
        }
        return maxD;
    }
};
