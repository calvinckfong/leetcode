// 1395. Count Number of Teams
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), result = 0;
        for (int i=0; i<n-2; i++) {
            for (int j=i+1; j<n-1; j++) {
                if (rating[i] < rating[j]) {
                    for (int k=j+1; k<n; k++) {
                        result += (rating[k] > rating[j]);
                    }
                } else if (rating[i] > rating[j]) {
                    for (int k=j+1; k<n; k++) {
                        result += (rating[k] < rating[j]);
                    }
                }
            }
        }

        return result;
    }
};
