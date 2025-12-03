// 3625. Count Number of Trapezoids II
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        const int inf = 1e9;
        
        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<int, vector<float>> midToSlope;
        int res = 0;
        for (int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                float m, c;
                if (x1==x2) {
                    m = inf;
                    c = x1;
                } else {
                    m = (float)(y2-y1) / (x2-x1);
                    c = (float)(y1*dx - x1*dy) / dx; 
                }
                int mid = (x1+x2) * 10000 + (y1+y2);
                slopeToIntercept[m].push_back(c);
                midToSlope[mid].push_back(m); 
            }
        }

        for (auto& [_, sti]: slopeToIntercept) {
            if (sti.size() == 1) continue;
            map<float, int> cnt;
            for (float x: sti) {
                cnt[x]++;
            }

            int sum=0;
            for (auto& [_, c]: cnt) {
                res += sum * c;
                sum += c;
            }
        }

        for (auto& [_, mts]: midToSlope) {
            if (mts.size() == 1) continue;

            map<float, int> cnt;
            for (float k: mts) {
                cnt[k]++;
            }

            int sum = 0;
            for (auto& [_, c]: cnt) {
                res -= sum * c;
                sum += c;
            }
        }
        return res;
    }
};
