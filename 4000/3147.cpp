// 3147. Taking Maximum Energy From the Mystic Dungeon
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        int n = energy.size();
        for (int i=n-k; i<n; i++) {
            int sum = 0;
            for (int j=i; j>=0; j-=k) {
                sum += energy[j];
                res = max(res, sum);
            }
        }
        return res;
    }
};
