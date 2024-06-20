// 1552. Magnetic Force Between Two Balls
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l=0, r=position.back()-position.front();
        while (l<r) {
            int mid = r-(r-l)/2;
            if (count(position, mid)>=m)
                l = mid;
            else
                r = mid-1;
        }
        return l;
    }
private:
    int count(vector<int>& position, int d) {
        int result = 1;
        for (int i=1, curr=position[0]; i<position.size(); i++) {
            if (position[i]-curr>=d) {
                result++;
                curr = position[i];
            }
        }
        return result;
    }
};
