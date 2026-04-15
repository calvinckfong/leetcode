// 2515. Shortest Distance to Target String in a Circular Array
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = n;
        for (int i=-(n+1)/2; i<(n+1)/2; i++) {
            if (target == words[(startIndex+i+n)%n]) {
                res = min(res, abs(i));
            }
        }
        return (res==n)?-1:res;
    }
};
