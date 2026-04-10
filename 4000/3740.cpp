// 3740. Minimum Distance Between Three Equal Elements I
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i=0; i<nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        int res = 300;
        for (auto& [key, pos]: m) {
            int n = pos.size();
            if (n>=3) {
                for (int i=0; i<n-2; i++) {
                    int ii = pos[i];
                    for (int j=i+1; j<n-1; j++) {
                        int jj = pos[j];
                        for (int k=j+1; k<n; k++) {
                            int kk = pos[k];
                            int dist = abs(ii-jj) + abs(jj-kk) + abs(kk-ii);
                            res = min(res, dist);
                        }
                    }
                }
            }
        }
        return (res==300) ? -1: res;
    }
};
