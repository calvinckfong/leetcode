// 3019. Number of Changing Keys
class Solution {
public:
    int countKeyChanges(string s) {
        int cnt=0;
        for (int i=1; i<s.size(); i++)
        {
            if (tolower(s[i-1])!=tolower(s[i])) cnt++;
        }
        return cnt;
    }
};
