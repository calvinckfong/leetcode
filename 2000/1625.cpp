// 1625. Lexicographically Smallest String After Applying Operations
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> vis(n);
        string res = s;

        s += s;
        for (int i=0; vis[i]==0; i=(i+b)%n) {
            vis[i] = 1;
            for (int j=0; j<10; j++) {
                int max_k = (b%2)?9:0;
                for (int k=0; k<=max_k; k++) {
                    string t = s.substr(i, n);
                    for (int p=1; p<n; p+=2) {
                        t[p] = '0' + (t[p]-'0'+j*a)%10;
                    }
                    for (int p=0; p<n; p+=2) {
                        t[p] = '0' + (t[p]-'0'+k*a)%10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};
