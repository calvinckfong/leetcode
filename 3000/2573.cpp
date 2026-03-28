// 2573. Find the String with LCP
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string res(n, 0);
        char curr = 'a';

        for (int i=0; i<n; i++) {
            if (res[i] == 0) {
                if (curr > 'z') return "";
            
                res[i] = curr;
                for (int j=i+1; j<n; j++) {
                    if (lcp[i][j] > 0) {
                        res[j] = res[i];
                    }
                }
                curr++;
            }
        }

        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int& x = lcp[i][j]; 
                if (res[i]!=res[j]) {
                    if (x) return "";
                } else {
                    if (i==n-1 || j==n-1) {
                        if (x!=1) return "";
                    } else {
                        if (x != lcp[i+1][j+1]+1) return "";
                    }
                }
            }
        }

        return res;
    }
};
