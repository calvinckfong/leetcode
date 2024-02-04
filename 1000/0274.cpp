// 274. H-Index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n=citations.size();
        for (int h=0; h<n; h++)
        {
            if (citations[n-1-h] < h+1) return h;
        }
        return n;
    }
};
