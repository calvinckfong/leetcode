// 1784. Check if Binary String Has at Most One Segment of Ones
class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0, nSeg = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='1') {
                cnt++;
            } else if (cnt) {
                nSeg++;
                if (nSeg>1) return false;
                cnt = 0;
            }
        }
        nSeg += (cnt>0);
        return nSeg<=1; 
    }
};
