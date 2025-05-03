// 1007. Minimum Domino Rotations For Equal Row
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int freq[7] = {0};
        for (int i=0; i<n; i++) {
            freq[tops[i]]++;
            if (bottoms[i] != tops[i]) freq[bottoms[i]]++;
        }

        int result = n;
        for (int i=1; i<7; i++) {
            if (freq[i] < n) continue;

            int keepTop=0, keepBottom=0;
            for (int j=0; j<n; j++) {
                if (tops[j]!=i) keepTop++;
                if (bottoms[j]!=i)   keepBottom++;
            }
            result = min(result, keepTop);
            result = min(result, keepBottom);
        }

        return (result==n) ? -1 : result;
    }
};
