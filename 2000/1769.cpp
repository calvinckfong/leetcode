// 1769. Minimum Number of Operations to Move All Balls to Each Box
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n);
        int nl=0, nr=0;
        int ml=0, mr=0;

        for (int j,i=0; i<n; i++) {
            result[i] += ml;
            nl += boxes[i] -'0';
            ml += nl;

            j = n-1-i;
            result[j] += mr;
            nr += boxes[j] - '0';
            mr += nr;
        }
        return result;
    }
};
