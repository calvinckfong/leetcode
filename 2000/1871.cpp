// 1871. Jump Game VII
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), prev(n);
        f[0] = 1;

        for (int i=0; i<minJump; i++)
            prev[i] = 1;

        for (int i=minJump; i<n; i++) {
            int l = i-maxJump, r = i-minJump;
            if (s[i] == '0') {
                int tmp = prev[r] - (l<=0 ? 0 : prev[l-1]);
                f[i] = (tmp!=0);
            }
            prev[i] = prev[i-1] + f[i];
        }
        return f[n-1];
    }
};
