// 3014. Minimum Number of Pushes to Type Word I
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int q = n/8;
        int r = n%8;
        return (q*4 + r)*(q+1);
    }
};
