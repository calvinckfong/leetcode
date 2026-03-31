// 3474. Lexicographically Smallest Generated String
class Solution {
public:
    string generateString(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        string res(n1+n2-1, 'a');
        vector<bool> fixed(n1+n2-1, false);
        for (int i=0; i<n1; i++) {
            if (str1[i] == 'T') {
                for (int j=i; j<i+n2; j++) {
                    if (fixed[j] && res[j]!=str2[j-i]) {
                        return "";
                    } else {
                        res[j] = str2[j-i];
                        fixed[j] = 1;
                    }
                }
            }
        }

        for (int i=0; i<n1; i++) {
            if (str1[i] == 'F') {
                bool flag = false;
                int idx = -1;
                for (int j=i+n2-1; j>=i; j--) {
                    if (str2[j-i]!=res[j]) flag = true;
                    if (idx==-1 && !fixed[j]) idx = j;
                }
                if (flag) continue;
                else if (idx != -1) res[idx] = 'b';
                else return "";
            }
        }
        return res;
    }
};
