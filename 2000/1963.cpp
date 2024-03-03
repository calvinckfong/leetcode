// 1963. Minimum Number of Swaps to Make the String Balanced
class Solution {
public:
    int minSwaps(string s) {
        int closeCnt=0, maxCloseCnt=0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]==']') {
                closeCnt++;
                if (closeCnt>maxCloseCnt) maxCloseCnt = closeCnt;
            }
            else closeCnt--;
        }
        return (maxCloseCnt+closeCnt+1)/2;
    }
};
