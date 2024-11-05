// 2914. Minimum Number of Changes to Make Binary String Beautiful
class Solution {
public:
    int minChanges(string s) {
        int n=s.size(), result=0; 
        for (int i=0; i<n; i+=2) {
            result += (s[i] != s[i+1]);
        }
        return result;
    }
};
