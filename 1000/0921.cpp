// 921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(), open=0, st=0;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') open++;
            else if (open>0) open--;
            else st++; 
        }
        return open+st;
    }
};
