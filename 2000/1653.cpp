// 1653. Minimum Deletions to Make String Balanced
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int a_cnt = 0, b_cnt=0;

        for (int i=0; i<n; i++) 
            a_cnt += (s[i]=='a');

        int result = n;
        for (int i=0; i<n; i++) {
            if (s[i]=='a') a_cnt--;
            result = min(result, a_cnt + b_cnt);
            if (s[i]=='b') b_cnt++;
        }
        return result;
    }
};
