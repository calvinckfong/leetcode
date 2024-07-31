// 1105. Filling Bookcase Shelves
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> DP(n+1, 0);

        for (int i=1; i<=n; i++) {

            int accuW = books[i-1][0];
            int maxH = books[i-1][1];
            DP[i] = DP[i-1] + maxH; 
            
            // re-arrange latest book
            int j = i-1;
            while (j>0 && accuW+books[j-1][0]<=shelfWidth) {
                accuW += books[j-1][0];
                maxH = max(maxH, books[j-1][1]);
                DP[i] = min(DP[i], DP[j-1]+maxH);
                j--;
            }
        }
        return DP[n];
    }
};
