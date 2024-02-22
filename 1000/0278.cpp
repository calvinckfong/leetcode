// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// 278. First Bad Version
class Solution {
public:
    int firstBadVersion(int n) {
        if (!isBadVersion(1) && n==1) return 1;
        
        // search using binary search
        int l=1, r=n;
        int ver = l + (r-l)/2;
        while (l<r)
        {
            if (isBadVersion(ver))
                r = ver;
            else
                l = ver+1;
            ver = l + (r-l)/2;
        }
        return ver;
    }
};
