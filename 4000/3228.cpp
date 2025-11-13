// 3228. Maximum Number of Operations to Move Ones to the End
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int cnt1=(s[0]=='1'), res=0;
        
        for (int i=1; i<n; i++) {
            if (s[i]=='1') cnt1++;
            else if (s[i-1]=='1') res+=cnt1;
        }
        return res;
    }
};
