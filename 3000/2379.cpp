// 2379. Minimum Recolors to Get K Consecutive Black Blocks
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w=0, l=0, r=0, n=blocks.size();
        int result = n;

        while (r<n) {
            if (blocks[r]=='W') w++;

            if (r-l+1 == k) {
                result = min(result, w);
                if (blocks[l]=='W') w--;
                l++;
            }
            r++;
        }
        return result;
    }
};
