// 2937. Make Three Strings Equal
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1==s2 && s2==s3) return 0;
        if (s1[0]!=s2[0] || s2[0]!=s3[0]) return -1;

        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        int p=0;
        
        while (p<l1 && p<l2 && p<l3)
        {
            if (s1[p]==s2[p] && s2[p]==s3[p])
                p++;
            else
                break;
        }
        return l1+l2+l3-3*p;
    }
};
